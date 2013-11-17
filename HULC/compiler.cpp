#include "C:\compil\TX\TXLib.h"
#include "hulcGDI.h"


//int translater(char names[NUMCMD][NUMOFSYMBOLINCMD], FILE* log);
//bool asmSecurity (FILE* man, FILE* asmf);



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

//int translater (char names[NUMCMD][NUMOFSYMBOLINCMD], FILE* log)
//{
//const  char* dirf = "DATA/dir.txt";
//FILE*  dirr = fopen (dirf, "r");
//assert (dirr);
//char   dirs[MAXDIRLEN] = {};
//fscanf (dirr ,"%s", dirs);
//fclose (dirr);
//
//const char* manf = txInputBox ("Введите полное имя файла", "system", dirs);
//FILE* man = fopen ($ (manf), "r");
//assert (man);
//
//FILE* dirw = fopen (dirf, "w");
//fprintf (dirw , "%s", manf);
//fclose (dirw);
//const char* asmff = "DATA/asm.txt";
//FILE* asmf = fopen (asmff, "w");
//assert (asmf);
//
//double pushch = 0;
//int ireg = 0;
//
//char deystvie[NUMOFSYMBOLINCMD] = "";
//
//assert (man);
//
//int kolvostrok = 0;
//fscanf (man, "%d", &kolvostrok);
//fprintf (asmf, "%d ", kolvostrok);
//
//asmSecurity (man, asmf);
//
//for (int i = 0; ;i++)
//    {
//    fscanf (man, "%s", deystvie);
//    fprintf (log, "I'm a helper Hulc - Great&Awful Mouse. I translator %s action %d\n", deystvie, i);
//
//////    if (strcmp (deystvie ,names[1]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdLINE);
//////        }
//////
//////    if (strcmp (deystvie ,names[2]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdCOPY);
//////        }
//////
//////    if (strcmp (deystvie ,names[3]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdBUCKET);
//////        }
//////
//////    if (strcmp (deystvie ,names[4]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdOUT);
//////        }
//////
//////    if (strcmp (deystvie ,names[5]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdJUMP);
//////        }
//////
//////    if (strcmp (deystvie ,names[6]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdCOLOR);
//////        }
//////
//////    if (strcmp (deystvie, names[7]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdCIRCLE);
//////        }
//////
//////    if (strcmp (deystvie, names[8]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdRECTANGLE);
//////        }
//////
//////    if (strcmp (deystvie, names[9]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdTRIANGLE);
//////        }
//////
//////    if (strcmp (deystvie,names[10]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdADD);
//////        }
//////
//////    if (strcmp (deystvie,names[11]) == 0)
//////        {
//////        fscanf (man, "%lg", &pushch);
//////        fprintf (asmf, "%d %lg ", cmdPUSH, pushch);
//////        }
//////
//////    if (strcmp (deystvie,names[12]) == 0)
//////        {
//////        fscanf (man, "%d", &ireg);
//////        fprintf (asmf, "%d %d ", cmdPUSHR, ireg);
//////        }
//////
//////    if (strcmp (deystvie,names[13]) == 0)
//////        {
//////        fscanf (man, "%d", &ireg);
//////        fprintf (asmf, "%d %d ", cmdPOPR, ireg);
//////        }
//////
//////    if (strcmp (deystvie,names[14]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdSUB);
//////        }
//////
//////    if (strcmp (deystvie,names[15]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdMUL);
//////        }
//////
//////    if (strcmp (deystvie,names[16]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdDIV);
//////        }
//////
//////    if (strcmp (deystvie,names[17]) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdIN);
//////        }
//////
//////    if (strcmp ($ (deystvie), $ (EXIT)) == 0)
//////        {
//////        fprintf (asmf, "%d ", cmdEXIT);
//////        break;
//////        }
//    }
//fclose (asmf);
//
//return 0;
//}
//
//bool asmSecurity (FILE* man, FILE* asmf)
//{
//int version = 0;
//int security1 = 0, security2 = 0, security3 = 0, security4 = 0;
//
//fscanf (man, "%d", &version);
//
//switch (version)
//    {
//    case 1: fscanf (man, "%d", &security1); fscanf (man, "%d", &security2); fscanf (man, "%d", &security3); break;
//    case 2: fscanf (man, "%d", &security1); fscanf (man, "%d", &security2); fscanf (man, "%d", &security3); break;
//    case 3: fscanf (man, "%d", &security1); fscanf (man, "%d", &security2); fscanf (man, "%d", &security3); fscanf (man, "%d", &security4); break;
//    case 4: fscanf (man, "%d", &security1); fscanf (man, "%d", &security2); fscanf (man, "%d", &security3); fscanf (man, "%d", &security4); break;
//    default : txMessageBox ("unknown version"); return false;
//    }
//if (version == 1 || version == 2 )
//    fprintf (asmf, "%d %d %d %d ", version, security1, security2, security3);
//if (version == 3 || version == 4 )
//    fprintf (asmf, "%d %d %d %d %d ", version, security1, security2, security3, security4);
//return true;
//}
