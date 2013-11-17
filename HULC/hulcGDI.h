enum cmdHulc
    {
    cmdPUSH         = 1,
    cmdADD          = 4,
    cmdSUB          = 5,
    cmdMUL          = 6,
    cmdDIV          = 7,
    cmdPUSHR        = 2,
    cmdPOPR         = 3,
    cmdLINE         = 8,
    cmdCOLOR        = 9,
    cmdCIRCLE       = 10,
    cmdRECTANGLE    = 11,
    cmdTRIANGLE     = 12,
    cmdBUCKET       = 13,
    cmdJUMP         = 14,
    cmdOUT          = 15,
    cmdIN           = 16,
    cmdCOPY         = 17,
    cmdEXIT         = 0,
    };

    char PUSH[]         = "push";
    char ADD[]          = "add";
    char SUB[]          = "sub";
    char MUL[]          = "mul";
    char DIV[]          = "div";
    char PUSHR[]        = "pushr";
    char POPR[]         = "popr";
    char LINE[]         = "line";
    char COLOR[]        = "color";
    char CIRCLE[]       = "circle";
    char RECTANGLE[]    = "rectangle";
    char TRIANGLE[]     = "triangle";
    char BUCKET[]       = "bucket";
    char JUMP[]         = "jump";
    char OUTT[]          = "out";
    char INN[]          = "in";
    char COPY[]         = "copy";
    char EXIT[]         = "exit";

const int NUMOFSYMBOLINCMD = 20;
const int NUMCMD = 18;
const int MAXFILENAME = 25;
const int MAXDIRLEN = 300;

#define HULC Hyper_Ultimate_Language_of_Computing
