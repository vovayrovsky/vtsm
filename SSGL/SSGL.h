#include "Z:\TX\TXlib.h"

void ssglCircleClear (COLORREF c, int r ,int  w,int  l);//(color,  ,screen's width, screen's length)
void ssglCircleLine (COLORREF cf, COLORREF cfme, int x, int y, int xp, int yp, int t, int r); //(color of fill ,color of frame ,previous x, previous y, +x, +y, tacts, radius)
//void ssglSimpleCircleLine (COLORREF c, int x, int y, int dir,)

void ssglCircleClear (COLORREF c,int  r ,int  w,int l)
{
txSetColor (c);
txSetFillColor (c);
while (r < w/2)
 {
 r+=5;
 txCircle (w/2, l/2, r);
 txSleep (1);
 }
txClear ();
}

void ssglCircleLine (COLORREF cf, COLORREF cfme, int x, int y, int xp, int yp, int t, int r)
{
txSetFillColor (cf);
txSetColor (cfme);
while (t > 0)
    {
    txCircle (x, y, r);
    x += xp;
    y += yp;
    t--;
    txSleep (1);
    }

}
