#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <time.h>
#include <math.h>

int main()
{
    int x, y, colore, k, x1, y1, r, coloreselezionato, i, pennello;
    colore=1;
    x=300;
    x1=0;
    y=0;
    y1=100;
    initwindow(1600,1000);

    //schermata
    setcolor(WHITE);
    line(0, 100, 1600, 100);
    line(100, 0, 100, 1000);
    x=100;
    for(k=0; k<14; k++)
    {
        line(x,y,x,y1);
        x=x+100;
    }

    x=100;
    y=200;
    for(k=0; k<10; k++)
    {
        line(x, y, x1, y);
        y=y+100;
    }

    x=101;
    y=0;
    for(k=0; k<16; k++)
    {
        setfillstyle(1, colore);
        floodfill(x,y,WHITE);
        colore++;
        x=x+100;
    }

    x=50;
    y=150;
    r=4;
    for(k=0;k<8;k++)
    {
        setfillstyle(1, WHITE);
        circle(x,y,r);
        floodfill(x,y,WHITE);
        y=y+100;
        r=r+4;
        setfillstyle(1, BLUE);
        bar(10, 916, 85, 999);
    }


    //interazione con il mouse
    while(true)
    {
        while(ismouseclick(WM_LBUTTONDOWN)==false)
        {}
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(y<128)
        {
            coloreselezionato=(x/100);
        }
        else
        {
            if(x<256)
            {
                i=(y-128)/256;
                pennello=(i+1)*20;
                if(i==3)
                {
                    pennello=20;
                    coloreselezionato=0;
                }
            }
            else
            {
                clearmouseclick(WM_LBUTTONUP);
                do
                {
                    if(x>256+pennello && y>128+pennello)
                    {
                        setcolor(coloreselezionato);
                        circle(x,y,pennello);
                        setfillstyle(1,coloreselezionato);
                        floodfill(x,y,coloreselezionato);
                    }

                    if(ismouseclick(WM_MOUSEMOVE)==true)
                    {
                        getmouseclick(WM_MOUSEMOVE,x,y);
                    }
                }while(ismouseclick(WM_LBUTTONUP)==false);
            }
        }
    }
}
