#include "translater.h"
const int KOLVOELEMENTSINMASSIV = 12;

class Stack
{
public:
double data[KOLVOELEMENTSINMASSIV];
int kolvo;
double regx[KOLVOELEMENTSINMASSIV];
int ireg;

void Printfv ();
void push (double pushchislo);
double pop ();
void Vplus ();
void Vminus ();
void Vumnozhity ();
void Vdeleniye ();
void popr (int regi);
void pushr (int regi);
};

//int main ()
//{
//txCreateWindow (1080, 720);
//double massiv[KOLVOELEMENTSINMASSIV] = {};
//int kolvo = 0;
//
//double pushch = 0;
//char mdo[5] = "";
//
//while (! GetAsyncKeyState (VK_ESCAPE))
//    {
//    printf ("¬ведите действие: ");
//    scanf ("%s", mdo);
//
//    if (*mdo == *ADD)
//        Vplus (massiv, &kolvo);
//
//    if (*mdo == *PUSH)
//        Vpush (massiv, &pushch, &kolvo);
//
//    if (*mdo == *SUB)
//        Vminus (massiv, &kolvo);
//
//    if (*mdo == *MUL)
//        Vumnozhity (massiv, &kolvo);
//
//    if (*mdo == *DIV)
//        Vdeleniye (massiv, &kolvo);
//    }
//}

void Stack::Printfv ()
{
for (int i = 0; i < kolvo; i++)
    {
    printf ("[%d] %lg ", i, data[i]);
    if (kolvo-1 == i)
        printf ("\n");
    }
}

void Stack::push (double pushchislo)
{
if (kolvo >= 12)
    {
    txMessageBox ("ERROR, there is not enough space in the array", "push");
    return;
    }

data[kolvo] = pushchislo;
kolvo++;
}

double Stack::pop ()
{
if (kolvo < 0)
    {
    txMessageBox ("ERROR, not enough elements in the array", "pop");
    return 0;
    }

kolvo--;
double returnch = data [kolvo];
data [kolvo] = 0;
return returnch;
}

void Stack::Vplus ()
{
double plus1 = pop (), plus2 = pop ();
push(plus1+plus2);
}

void Stack::Vminus ()
{
double plus1 = pop (), plus2 = pop ();
push(plus1-plus2);
}

void Stack::Vumnozhity ()
{
double plus1 = pop (), plus2 = pop ();
push(plus1*plus2);
}

void Stack::Vdeleniye ()
{
double plus1 = pop (), plus2 = pop ();
push(plus1/plus2);
}

void Stack::popr (int regi)
{
if (regi < 0 || regi > KOLVOELEMENTSINMASSIV)
    {
    txMessageBox("You got out for the bound of the array.");
    return;
    }

regx[regi] = pop ();
}

void Stack::pushr (int regi)
{
if (regi < 0 || regi > KOLVOELEMENTSINMASSIV)
    {
    txMessageBox("You got out for the bound of the array.");
    return;
    }

int pushch = regx[regi] ;
push (pushch);
regx[regi] = 0;
}
// (345-50)/(23+34)=

//             []
// push 345    [345]
// push 50     [345 50]
// sub         [295]
// push 23     [295]
// push 34     [295 23 34]
// add         [295 57]
// div         [5.17]
// push 0

// r0

// pushr r9    fscanf (f, "r%d", &n)
// popr r0

