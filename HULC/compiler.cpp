#include "C:\compil\TX\TXLib.h"
#include "hulcGDI.h"

int main(int argc, char **argv)
{
if (argc != 2)
    {
    txMessageBox("Haven't file for compil");
    return 1;
    }

FILE* f = fopen (argv[1], "r");
assert (f);

FILE* log = fopen ("log.txt", "a");
assert (log);

char name[MAXFILENAME] = "";
printf ("Input name of output file with .hulc");
scanf ("%s", name);
FILE* out = fopen (name, "w");
assert (out);

char deystvie[NUMOFSYMBOLINCMD] = "";
double pushch = 0, ireg = 0;
for (int i = 0; ; i++)
    {
    fscanf (f, "%s", deystvie);
    fprintf (log, "scanf %s action %d", deystvie, i);
    if (strcmp (deystvie ,LINE) == 0)
        {
        fprintf (out, "%d ", cmdLINE);
        }

    if (strcmp (deystvie ,COPY) == 0)
        {
        fprintf (out, "%d ", cmdCOPY);
        }

    if (strcmp (deystvie ,BUCKET) == 0)
        {
        fprintf (out, "%d ", cmdBUCKET);
        }

    if (strcmp (deystvie ,OUTT) == 0)
        {
        fprintf (out, "%d ", cmdOUT);
        }

    if (strcmp (deystvie ,JUMP) == 0)
        {
        fprintf (out, "%d ", cmdJUMP);
        }

    if (strcmp (deystvie ,COLOR) == 0)
        {
        fprintf (out, "%d ", cmdCOLOR);
        }

    if (strcmp (deystvie ,CIRCLE) == 0)
        {
        fprintf (out, "%d ", cmdCIRCLE);
        }

    if (strcmp (deystvie ,RECTANGLE) == 0)
        {
        fprintf (out, "%d ", cmdRECTANGLE);
        }

    if (strcmp (deystvie ,TRIANGLE) == 0)
        {
        fprintf (out, "%d ", cmdTRIANGLE);
        }

    if (strcmp (deystvie ,ADD) == 0)
        {
        fprintf (out, "%d ", cmdADD);
        }

    if (strcmp (deystvie ,PUSH) == 0)
        {
        fscanf (f, "%lg", &pushch);
        fprintf (out, "%d %lg ", cmdPUSH, pushch);
        }

    if (strcmp (deystvie ,PUSHR) == 0)
        {
        fscanf (f, "%d", &ireg);
        fprintf (out, "%d %d ", cmdPUSHR, ireg);
        }

    if (strcmp (deystvie ,POPR) == 0)
        {
        fscanf (f, "%d", &ireg);
        fprintf (out, "%d %d ", cmdPOPR, ireg);
        }

    if (strcmp (deystvie ,SUB) == 0)
        {
        fprintf (out, "%d ", cmdSUB);
        }

    if (strcmp (deystvie ,MUL) == 0)
        {
        fprintf (out, "%d ", cmdMUL);
        }

    if (strcmp (deystvie ,DIV) == 0)
        {
        fprintf (out, "%d ", cmdDIV);
        }

    if (strcmp (deystvie ,INN) == 0)
        {
        fprintf (out, "%d ", cmdIN);
        }

    if (strcmp (deystvie, EXIT) == 0)
        {
        fprintf (out, "%d ", cmdEXIT);
        fclose (f);
        fclose (out);
        fclose (log);
        return 0;
        }
    }
}
