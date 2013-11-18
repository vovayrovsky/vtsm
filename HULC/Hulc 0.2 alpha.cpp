#include "stec.h"

void txTriangle (int x, int y, int x1, int y1, int x2, int y2);
void line (Stack* stk);
void color (Stack* stk, COLORREF* cvet);
void clearw (Stack* stk);
void circle (Stack* stk);
void rectangle (Stack* stk);
void triangle (Stack* stk);
void jump (Stack* stk, int* element);
void out (Stack* stk);
void in (Stack* stk);
void copynum (Stack* stk);

int vers1 (FILE* man);
int vers2 (FILE* man);
int vers3 (FILE* man);
int vers4 (FILE* man);

int main (int argc, char **argv)
{
if (argc != 2)
    {
    txMessageBox("Haven't file for play");
    return 1;
    }
txTextCursor (false);
txCreateWindow (1080, 720);
txSetFillColor (TX_WHITE);

const char* logf = "DATA/log.txt";
FILE* log = fopen (logf, "a");

fprintf (log, "\n\n=========hulc started=========\n");

FILE* read = fopen (argv[1], "r");

COLORREF cvet = TX_WHITE;

Stack stk = {};
double pushch = 0;

double deystvie = 0;

int cmd = 0;

int element = 0;

double proga[MAXSYMBOLINCOMMANDFILE];

fprintf (log, "\n\n\n=========hulc read and printf to array of programm do =========\n");
    for ( ; element <= MAXSYMBOLINCOMMANDFILE; element++)
        {
        txSetColor (cvet);
        txSetFillColor (cvet);
        fscanf (read, "%lg", &deystvie);
        proga[element] = deystvie;
        fprintf (log, "hulc printf to array of programm %lg\n", deystvie);
/*        switch (deystvie)
            {
            case cmdLINE:       proga[element] = cmdLINE;                                                                                   element++;              break;
            case cmdBUCKET:     proga[element] = cmdBUCKET;                                                                                 element++;              break;
            case cmdJUMP:       proga[element] = cmdJUMP;                                                                                   element++;              break;
            case cmdOUT:        proga[element] = cmdOUT;                                                                                    element++;              break;
            case cmdCOLOR:      proga[element] = cmdCOLOR;                                                                                  element++;              break;
            case cmdCIRCLE:     proga[element] = cmdCIRCLE;                                                                                 element++;              break;
            case cmdRECTANGLE:  proga[element] = cmdRECTANGLE;                                                                              element++;              break;
            case cmdTRIANGLE:   proga[element] = cmdTRIANGLE;                                                                               element++;              break;
            case cmdADD:        proga[element] = cmdADD;                                                                                    element++;              break;
            case cmdPUSH:       proga[element] = cmdPUSH; element++; fscanf (read, "%lg", &pushch); proga[element] = pushch;                element++;              break;
            case cmdPUSHR:      proga[element] = cmdPUSHR; element++; fscanf (read, "%lg", &stk.ireg); proga[element] = stk.ireg;           element++;              break;
            case cmdPOPR:       proga[element] = cmdPOPR; element++; fscanf (read, "%lg", &stk.ireg); proga[element] = stk.ireg;            element++;              break;
            case cmdSUB:        proga[element] = cmdSUB;                                                                                    element++;              break;
            case cmdMUL:        proga[element] = cmdMUL;                                                                                    element++;              break;
            case cmdDIV:        proga[element] = cmdDIV;                                                                                    element++;              break;
            case cmdEXIT:       proga[element] = cmdEXIT;                                                                                                           break;
            }*/
        }
        element++;
        proga[element] = cmdEXIT;

    fprintf (log, "\n\n======hulc end read program and he start do this is program======\n\n\n");

    deystvie = 0;
    pushch = 0;
    element = 0;
    stk.ireg = 0;
    pushch = 0;
    stk.ireg = 0;
    for (int i = 0; i <= MAXSYMBOLINCOMMANDFILE; i++)
        {
        txSetColor (cvet);
        txSetFillColor (cvet);
        cmd = proga[element];
        switch (cmd)
            {
            case cmdCOPY: copynum (&stk);                                                element++; break;
            case cmdLINE: line (&stk);                                                   element++; break;
            case cmdPUSH: element++; pushch = proga[element]; stk.push (pushch);         element++; break;
            case cmdBUCKET: clearw (&stk);                                               element++; break;
            case cmdOUT: out (&stk);                                                     element++; break;
            case cmdJUMP: jump (&stk, &element);                                                    break;
            case cmdCOLOR: color (&stk, &cvet);                                          element++; break;
            case cmdCIRCLE: circle (&stk);                                               element++; break;
            case cmdRECTANGLE: rectangle (&stk);                                         element++; break;
            case cmdTRIANGLE: triangle (&stk);                                           element++; break;
            case cmdADD: stk.Vplus ();                                                   element++; break;
            case cmdPUSHR: element++; stk.ireg = proga[element]; stk.pushr (stk.ireg);   element++; break;
            case cmdPOPR: element++; stk.ireg = proga[element]; stk.popr (stk.ireg);     element++; break;
            case cmdSUB: stk.Vminus ();                                                  element++; break;
            case cmdMUL: stk.Vumnozhity ();                                              element++; break;
            case cmdDIV: stk.Vdeleniye ();                                               element++; break;
            case cmdIN: in(&stk);                                                        element++; break;
            case cmdEXIT: fprintf (log, "\n\n ========hulc end do programm, number 0========"); return 0;
            default: txMessageBox ("ERROR Code, program end.", "hulc"); fprintf (log, "ERROR Code, number 2\n"); return 1;
            }
        fprintf (log, "hulc do %d\n", cmd);
        }
    fprintf (log, "\n\n ========hulc end do programm, number 3 (but you haven't gave me cmdEXIT(you luser:) ))========");
    return 3;
    }

void txTriangle (int x, int y, int x1, int y1, int x2, int y2)
{
POINT triangle[4] = {{x, y}, {x1, y1}, {x2, y2}, {x, y}};
txPolygon (triangle, 4);
}

void line (Stack* stk)
{
int x = stk->pop (), y = stk->pop (), x1 = stk->pop (), y1 = stk->pop ();
txLine (x, y, x1, y1);
}

void color (Stack* stk, COLORREF* cvet)
{
int R = stk->pop (), G = stk->pop (), B = stk->pop ();
*cvet = RGB (R, G, B);
}

void clearw (Stack* stk)
{
int R = stk->pop (), G = stk->pop (), B = stk->pop ();
txSetFillColor (RGB (R, G, B));
txClear ();
}

void circle (Stack* stk)
{
int x = stk->pop (), y = stk->pop (), r = stk->pop ();
txCircle (x, y, r);
}

void rectangle (Stack* stk)
{
int x = stk->pop (), y = stk->pop (), x1 = stk->pop (), y1 = stk->pop ();
txRectangle (x, y, x1, y1);
}

void triangle (Stack* stk)
{
int xt = stk->pop (), yt = stk->pop (), xt1 = stk->pop (), yt1 = stk->pop (), xt2 = stk->pop (), yt2 = stk->pop ();
txTriangle (xt, yt, xt1, yt1, xt2, yt2);
}

void jump (Stack* stk, int* element)
{
int elm = stk->pop();
*element = elm;
}

void out (Stack* stk)
{
double outch = stk->pop ();
printf ("%lg \n", outch);
}

void in (Stack* stk)
{
double inch = 0;
printf ("введите число: ");
scanf ("%lg", &inch);
stk->push (inch);
}

void copynum (Stack* stk)
{
double outch = stk->pop();
stk->push (outch);
stk->push (outch);
}
