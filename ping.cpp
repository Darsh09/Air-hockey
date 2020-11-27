#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
void main()
{
 Play_Again:
 int gd=DETECT,gm;
 int xb,yb,xr,yr,xR,yR,key,maxx,maxy,midx,midy,xspeed,yspeed,win;
 char msg[50];
 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 maxx=getmaxx();
 maxy=getmaxy();
 midx=getmaxx()/2;
 midy=getmaxy()/2;
 xb=midx;
 yb=midy;
 xr=maxx-150;
 yr=maxy-25;
 xR=random(maxx);
 yR=5;
 xspeed=2;
 yspeed=2;
 setcolor(GREEN);
 while(1)
 {
   if(kbhit())
   {
     key=getch();
     if(key==106)
       xr-=8;
     else if(key==108)
       xr+=8;
     else if(key==97)
       xR-=8;
     else if(key==100)
       xR+=8;
     else if(key==27)
       break;
   }
   xb+=xspeed;
   yb+=yspeed;
   setcolor(WHITE);
   setlinestyle(1,1,3);
   line(1,1,1,maxy);
   line(1,1,maxx,1);
   line(1,maxy,maxx,maxy);
   line(maxx,1,maxx,maxy);
   setcolor(RED);
   setlinestyle(0,1,0);
   circle(xb,yb,10);
   if(xb>(maxx-10)||xb<10)
     xspeed*=(1-2);
   if(yb<10)
   {
     win=1;
     break;
   }
   if(yb>(maxy-10))
   {
     win=2;
     break;
   }
   if((yr<(yb+10)&&(yr+20)>(yb+10))&&(xr<(xb-10)&&(xr+140)>(xb+10)))
     yspeed*=(1-2);
   if(((yR+20)>(yb-10)&&yR<(yb-10))&&(xR<(xb-10)&&(xR+140)>(xb+10)))
     yspeed*=(1-2);
   setcolor(BROWN);
   rectangle(xr,yr,xr+140,yr+20);
   rectangle(xR,yR,xR+140,yR+20);
   delay(10);
   cleardevice();
 }
 cleardevice();
 settextstyle(4,0,5);
 setcolor(15);
 sprintf(msg,"Pong Game");
 outtextxy(midx-150,midy-80,msg);
 settextstyle(1,0,2);
 setcolor(BROWN);
 if(win==2)
   sprintf(msg,"Player-1 Win");
 else
   sprintf(msg,"Player-2 Win");
 outtextxy(midx-120,midy-10,msg);
 settextstyle(2,0,6);
 setcolor(GREEN);
 sprintf(msg,"Press Enter to play again...");
 outtextxy(150,midy+20,msg);
 if((getch()==13))
   goto Play_Again;
 getch();
 closegraph();
}