#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void rotate1();
void rotate2();
void show1();
void show2();
int dice1();
int dice2();
void detectmouse();
void showmousetext();
void hidemousetext();
void button1();
void button2();
int intro();
float bet();
union REGS in,out;
FILE *fp1,*fp2;
int u;
void main()
{
int c,i,m,g,h,grd,grm;
int left,top,right,bottom;
int margin,width,height;
int cx,cy,x,y;
int tone[30] = {349,330,415,466,415,456,262,456,262,456,262,456,415,456,262,456,262,456,415,415,456,415,456,415,330,349,330,349,330,349};
float l;
static float aob;
char buffer[]="WELCOME TO THE WHEEL OF FORTUNE",s[50],ch,ch1;
char *P[31]={"\033[22;32mE","N","T","E","R"," ","\033[22;31mY","O","U","R"," ","\033[22;36mN","A","M","E"," ",
"\033[01;37mA","N","D"," ","\033[01;33mP","R","E","S","S"," ","\033[22;35mE","N","T","E","R"};
detectgraph(&grd,&grm);
initgraph(&grd,&grm,"C:\\TURBOC3\\BGI");
clrscr();
fp1=fopen("NAME.txt","w+");
fp2=fopen("SCORE.txt","w+");
setbkcolor(BLUE);
for(i=0;i<=100;i++)
{
setcolor(i);
rectangle(i,i,getmaxx()-i,getmaxy()-i);
sound(49*i);
delay(10);
nosound();
}
width=textwidth(buffer);
height=textheight(buffer);
margin=100;
left=margin;
top=margin;
bottom=getmaxy()-margin;
right=getmaxx()-margin;
setfillstyle(SOLID_FILL,BLUE);
bar(left,top,right,bottom);
rectangle(left,top,right,bottom);
setcolor(RED);
cx=(right+left-width)/2;
cy=(bottom+top-height)/2;
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
outtextxy(cx-62,cy-20,buffer);
gotoxy(25,18);
sleep(1);
textbackground(BLUE);
for(i=0;i<=30;i++)
{
printf("%s",P[i]);
sound(tone[i]);
delay(100);
nosound();
}
gotoxy(37,19);
scanf("%[^\n]",s);
u=strlen(s);
fputs(s,fp1);
ch=getchar();
if(ch=='\n')
{
sound(1500);
delay(100);
nosound();
c=intro();
if(c==1)
{
sound(1500);
delay(100);
nosound();
clrscr();
cleardevice();
setbkcolor(GREEN);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
setcolor(WHITE);
outtextxy(getmaxx()/2-230,getmaxy()/2-180,"KINDLY CHOOSE THE MODE OF BET TO START!!!");
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
bar(getmaxx()/2-150,getmaxy()/2-80,getmaxx()/2+150,getmaxy()/2-50);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
bar(getmaxx()/2-150,getmaxy()/2-5,getmaxx()/2+150,getmaxy()/2+25);
setcolor(BLUE);
outtextxy(getmaxx()/2-60,getmaxy()/2-78,"Easy Mode");
setcolor(RED);
outtextxy(getmaxx()/2-72,getmaxy()/2-3,"Difficult Mode");
detectmouse();
showmousetext();
in.x.ax=0;
int86(0X33,&in,&in);
in.x.ax=1;
int86(0X33,&in,&in);
while(!kbhit())
{
in.x.ax=3;
x=in.x.cx;
y=in.x.dx;
int86(0X33,&in,&in);
if(x>getmaxx()/2-150 &&y>getmaxy()/2-80 && x<getmaxx()/2+150 && y<getmaxy()/2-50 && in.x.bx==1)
{
clrscr();
cleardevice();
sound(1800);
delay(100);
nosound();
l=bet();
rewind(fp2);
fscanf(fp2,"%f",&aob);
if(l!=0)
{
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show1();
button1();
}
}
if(x>getmaxx()/2-150&& y>getmaxy()/2-5 && x<getmaxx()/2+150 && y<getmaxy()/2+25 && in.x.bx==1)
{
clrscr();
cleardevice();
sound(1800);
delay(100);
nosound();
l=bet();
rewind(fp2);
fscanf(fp2,"%f",&aob);
if(l!=0)
{
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show2();
button2();
}
}
}
}
}
getch();
fclose(fp1);
fclose(fp2);
closegraph();
}
void show1()
{
int i,a,b,x=0,y=20,arad=10,brad=10;
char c[100];
for(i=1;i<=9;i++)
{
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,x,y,180,180);
x=y;
y+=20;
}
for(i=1;i<=9;i++)
{
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,x,y,180,180);
x=y;
y+=20;
}
dice1();
for(i=1;i<=18;i++)
{
a=((getmaxx()/2)+(90*cos((3.14/180.0)*arad)))-10;
b=((getmaxy()/2)+(90*sin((3.14/180.0)*brad)))-16;
sprintf(c,"%d",i);
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
setcolor(WHITE);
outtextxy(a,b,c);
arad+=20;
brad+=20;
}
}
void show2()
{
int i,a,b,x=0,y=20,arad=10,brad=10;
char c[100];
for(i=1;i<=9;i++)
{
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,x,y,180,180);
x=y;
y+=20;
}
for(i=1;i<=9;i++)
{
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,x,y,180,180);
x=y;
y+=20;
}
dice2();
for(i=1;i<=18;i++)
{
a=((getmaxx()/2)+(90*cos((3.14/180.0)*arad)))-10;
b=((getmaxy()/2)+(90*sin((3.14/180.0)*brad)))-16;
sprintf(c,"%d",i);
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
setcolor(WHITE);
outtextxy(a,b,c);
arad+=20;
brad+=20;
}
}
void rotate1()
{
int m,l,e=0,f=20,theta=0,arad=10,brad=10,a,b;
char c[100];
int i,j=1;
while(j<=19)
{
for(i=1;i<=9;i++)
{
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,e,f,180,180);
e=f;
f+=20;
}
for(i=1;i<=9;i++)
{
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,e,f,180,180);
e=f;
f+=20;
}
for(i=1;i<=18;i++)
{
e=0,f=20;
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,e,f,180,180);
e=e+theta;
f=f+theta;
}
dice1();
for(i=1;i<=18;i++)
{
a=((getmaxx()/2)+(90*cos((3.14/180.0)*arad)))-10;
b=((getmaxy()/2)+(90*sin((3.14/180.0)*brad)))-16;
sprintf(c,"%d",i);
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
setcolor(WHITE);
outtextxy(a,b,c);
arad+=20;
brad+=20;
}
delay(20);
j++;
theta+=20;
}
}
void rotate2()
{
int m,l,e=0,f=20,theta=0,arad=10,brad=10,a,b;
char c[100];
int i,j=1;
while(j<=19)
{
for(i=1;i<=9;i++)
{
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,e,f,180,180);
e=f;
f+=20;
}
for(i=1;i<=9;i++)
{
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,e,f,180,180);
e=f;
f+=20;
}
for(i=1;i<=18;i++)
{
e=0,f=20;
setfillstyle(SOLID_FILL,i);
setcolor(WHITE);
sector(getmaxx()/2,getmaxy()/2,e,f,180,180);
e=e+theta;
f=f+theta;
}
dice2();
for(i=1;i<=18;i++)
{
a=((getmaxx()/2)+(90*cos((3.14/180.0)*arad)))-10;
b=((getmaxy()/2)+(90*sin((3.14/180.0)*brad)))-16;
sprintf(c,"%d",i);
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
setcolor(WHITE);
outtextxy(a,b,c);
arad+=20;
brad+=20;
}
delay(20);
j++;
theta+=20;
}
}


void detectmouse()
{
in.x.ax = 0;
int86 (0X33,&in,&out);
}

void showmousetext()
{
in.x.ax = 1;
int86 (0X33,&in,&out);
}

void hidemousetext()
{
in.x.ax = 2;
int86(0X33,&in,&out);
}
void button1()
{
char z[17],m[17],s[50],ch,ch1;
int a[8]={261,294,329,349,392,440,493,523},b,i,j,e=38,f=25,x,y,t;
float l;
static float aob;
rewind(fp2);
fscanf(fp2,"%f",&aob);
rewind(fp1);
fgets(s,u+1,fp1);
setcolor(GREEN);
outtextxy(getmaxx()/18,0,"CLICK THE NUMBER HERE YOU WANT TO KEEP BET ON!!!");
for(i=0;i<=17;i++)
{
m[i]=i+1;
sprintf(z,"%d",m[i]);
setcolor(BLUE);
outtextxy(e+(30*i),f,z);
}
showmousetext();
detectmouse();
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setcolor(GREEN);
outtextxy(359,450,"Developers:Biplab,Alex,Anish,Mitesh");
in.x.ax=0;
int86(0X33,&in,&in);
in.x.ax=1;
int86(0X33,&in,&in);
while(!kbhit())
{
in.x.ax=3;
x=in.x.cx;
y=in.x.dx;
int86(0X33,&in,&in);
for(i=0;i<=18;i++)
{
if(x>(37+(30*i)) && x<(55+(30*i)) && y>25 && y<45 && in.x.bx ==1)
{
sound(1800);
delay(100);
nosound();
b=m[i];
rotate1();
show1();
if(b==dice1())
{
aob=aob*2;
rewind(fp2);
fprintf(fp2,"%f",aob);
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show1();
sound(2500);
delay(1000);
sound(1800);
delay(1000);
nosound();
button1();
}
else
{
aob=aob/2;
rewind(fp2);
fprintf(fp2,"%f",aob);
if(aob>=1.00)
{
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show1();
sound(2000);
delay(500);
nosound();
button1();
}
if(aob<1.00)
{
cleardevice();
show1();
for(i=0;i<8;i++)
{
sound(a[i]);
delay(500);
nosound();
}
cleardevice();
hidemousetext();
setbkcolor(MAGENTA);
settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
setcolor(WHITE);
outtextxy(getmaxx()/2-80,getmaxy()/2-20,"GAME OVER!!!");
outtextxy(getmaxx()/2-250,getmaxy()/2+50,"Press 1 To Play Again Else Press 0 To Exit!!!");
ch=getche();
if(ch=='1')
{
sound(1000);
delay(100);
nosound();
clrscr();
cleardevice();
setbkcolor(GREEN);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
setcolor(WHITE);
outtextxy(getmaxx()/2-230,getmaxy()/2-180,"KINDLY CHOOSE THE MODE OF BET TO START!!!");
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
bar(getmaxx()/2-150,getmaxy()/2-80,getmaxx()/2+150,getmaxy()/2-50);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
bar(getmaxx()/2-150,getmaxy()/2-5,getmaxx()/2+150,getmaxy()/2+25);
setcolor(BLUE);
outtextxy(getmaxx()/2-60,getmaxy()/2-78,"Easy Mode");
setcolor(RED);
outtextxy(getmaxx()/2-72,getmaxy()/2-3,"Difficult Mode");
detectmouse();
showmousetext();
in.x.ax=0;
int86(0X33,&in,&in);
in.x.ax=1;
int86(0X33,&in,&in);
while(!kbhit())
{
in.x.ax=3;
x=in.x.cx;
y=in.x.dx;
int86(0X33,&in,&in);
if(x>getmaxx()/2-150 &&y>getmaxy()/2-80 && x<getmaxx()/2+150 && y<getmaxy()/2-50 && in.x.bx==1)
{
clrscr();
cleardevice();
sound(1800);
delay(100);
nosound();
l=bet();
rewind(fp2);
fscanf(fp2,"%f",&aob);
if(l!=0)
{
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show1();
button1();
}
}
if(x>getmaxx()/2-150&& y>getmaxy()/2-5 && x<getmaxx()/2+150 && y<getmaxy()/2+25 && in.x.bx==1)
{
clrscr();
cleardevice();
sound(1800);
delay(100);
nosound();
l=bet();
rewind(fp2);
fscanf(fp2,"%f",&aob);
if(l!=0)
{
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show2();
button2();
}
}
}
}
}
}
if(ch=='0')
{
sound(1000);
delay(100);
nosound();
exit(0);
}
}
}
}
}
void button2()
{
char z[17],m[17],s[50],ch;
int a[8]={261,294,329,349,392,440,493,523},b,i,j,e=38,f=25,x,y,t;
float l;
static float aob;
rewind(fp2);
fscanf(fp2,"%f",&aob);
rewind(fp1);
fgets(s,u+1,fp1);
setcolor(GREEN);
outtextxy(getmaxx()/18,0,"CLICK THE NUMBER HERE YOU WANT TO KEEP BET ON!!!");
for(i=0;i<=17;i++)
{
m[i]=i+1;
sprintf(z,"%d",m[i]);
setcolor(BLUE);
outtextxy(e+(30*i),f,z);
}
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setcolor(GREEN);
outtextxy(359,450,"Developers:Biplab,Alex,Anish,Mitesh");
showmousetext();
detectmouse();
in.x.ax=0;
int86(0X33,&in,&in);
in.x.ax=1;
int86(0X33,&in,&in);
while(!kbhit())
{
in.x.ax=3;
x=in.x.cx;
y=in.x.dx;
int86(0X33,&in,&in);
for(i=0;i<=18;i++)
{
if(x>(37+(30*i)) && x<(55+(30*i)) && y>25 && y<45 && in.x.bx ==1)
{
sound(1800);
delay(100);
nosound();
b=m[i];
rotate2();
show2();
if(b==dice2())
{
aob=aob*2;
rewind(fp2);
fprintf(fp2,"%f",aob);
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show2();
sound(2500);
delay(1000);
sound(1800);
delay(1000);
nosound();
button2();
}
else
{
aob=aob/2;
rewind(fp2);
fprintf(fp2,"%f",aob);
if(aob>=1.00)
{
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show2();
sound(2000);
delay(500);
nosound();
button2();
}
if(aob<1.00)
{
cleardevice();
show2();
for(i=0;i<8;i++)
{
sound(a[i]);
delay(500);
nosound();
}
cleardevice();
hidemousetext();
setbkcolor(MAGENTA);
settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
setcolor(WHITE);
outtextxy(getmaxx()/2-80,getmaxy()/2-20,"GAME OVER!!!");
outtextxy(getmaxx()/2-250,getmaxy()/2+50,"Press 1 To Play Again Else Press 0 To Exit!!!");
ch=getche();
if(ch=='1')
{
sound(1000);
delay(100);
nosound();
clrscr();
cleardevice();
setbkcolor(GREEN);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
setcolor(WHITE);
outtextxy(getmaxx()/2-230,getmaxy()/2-180,"KINDLY CHOOSE THE MODE OF BET TO START!!!");
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
bar(getmaxx()/2-150,getmaxy()/2-80,getmaxx()/2+150,getmaxy()/2-50);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
bar(getmaxx()/2-150,getmaxy()/2-5,getmaxx()/2+150,getmaxy()/2+25);
setcolor(BLUE);
outtextxy(getmaxx()/2-60,getmaxy()/2-78,"Easy Mode");
setcolor(RED);
outtextxy(getmaxx()/2-72,getmaxy()/2-3,"Difficult Mode");
detectmouse();
showmousetext();
in.x.ax=0;
int86(0X33,&in,&in);
in.x.ax=1;
int86(0X33,&in,&in);
while(!kbhit())
{
in.x.ax=3;
x=in.x.cx;
y=in.x.dx;
int86(0X33,&in,&in);
if(x>getmaxx()/2-150 &&y>getmaxy()/2-80 && x<getmaxx()/2+150 && y<getmaxy()/2-50 && in.x.bx==1)
{
clrscr();
cleardevice();
sound(1800);
delay(100);
nosound();
l=bet();
rewind(fp2);
fscanf(fp2,"%f",&aob);
if(l!=0)
{
clrscr();
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show1();
button1();
}
}
if(x>getmaxx()/2-150&& y>getmaxy()/2-5 && x<getmaxx()/2+150 && y<getmaxy()/2+25 && in.x.bx==1)
{
clrscr();
cleardevice();
sound(1800);
delay(100);
nosound();
l=bet();
rewind(fp2);
fscanf(fp2,"%f",&aob);
if(l!=0)
{
cleardevice();
setbkcolor(RED);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
gotoxy(37,19);
printf("\n\n\n\n\n\n\n\n\nPLAYER'S NAME:%s",s);
printf("\nAmount On Bet:$%0.2f",aob);
show2();
button2();
}
}
}
}
}
}
if(ch=='0')
{
sound(1000);
delay(100);
nosound();
exit(0);
}
}
}
}
}
int dice1()
{
int i,s,p,w,a1,b1,m,n;
srand(time(NULL));
p=rand()%361;
a1=((getmaxx()/2)+(120*cos((3.14/180.0)*p)));
b1=((getmaxy()/2)+(120*sin((3.14/180.0)*p)));
setcolor(YELLOW);
setfillstyle(XHATCH_FILL,YELLOW);
circle(a1,b1,10);
floodfill(a1,b1,YELLOW);
if(p<=180)
{
m=(getmaxx()/2)+(120*cos((3.14/180.0)*0));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*20));
if((a1<=m) && (a1>=n))
{
w=1;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*20));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*40));
if((a1<=m) && (a1>=n))
{
w=2;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*40));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*60));
if((a1<=m) && (a1>=n))
{
w=3;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*60));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*80));
if((a1<=m) && (a1>=n))
{
w=4;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*80));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*100));
if((a1<=m) && (a1>=n))
{
w=5;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*100));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*120));
if((a1<=m) && (a1>=n))
{
w=6;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*120));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*140));
if((a1<=m) && (a1>=n))
{
w=7;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*140));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*160));
if((a1<=m) && (a1>=n))
{
w=8;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*160));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*180));
if((a1<=m) && (a1>=n))
{
w=9;
}
}
else
{
m=(getmaxx()/2)+(120*cos((3.14/180.0)*180));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*200));
if((a1>=m) && (a1<=n))
{
w=10;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*200));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*220));
if((a1>=m) && (a1<=n))
{
w=11;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*220));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*240));
if((a1>=m) && (a1<=n))
{
w=12;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*240));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*260));
if((a1>=m) && (a1<=n))
{
w=13;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*260));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*280));
if((a1>=m) && (a1<=n))
{
w=14;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*280));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*300));
if((a1>=m) && (a1<=n))
{
w=15;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*300));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*320));
if((a1>=m) && (a1<=n))
{
w=16;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*320));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*340));
if((a1>=m) && (a1<=n))
{
w=17;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*340));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*360));
if((a1>=m) && (a1<=n))
{
w=18;
}
}
return w;
}

int dice2()
{
int i,s,o,p,q,w,a1,b1,m,n;
o=rand()%361;
a1=((getmaxx()/2)+(120*cos((3.14/180.0)*o)));
b1=((getmaxy()/2)+(120*sin((3.14/180.0)*o)));
setcolor(YELLOW);
setfillstyle(XHATCH_FILL,YELLOW);
circle(a1,b1,10);
floodfill(a1,b1,YELLOW);
if(o<=180)
{
m=(getmaxx()/2)+(120*cos((3.14/180.0)*0));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*20));
if((a1<=m) && (a1>=n))
{
w=1;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*20));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*40));
if((a1<=m) && (a1>=n))
{
w=2;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*40));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*60));
if((a1<=m) && (a1>=n))
{
w=3;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*60));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*80));
if((a1<=m) && (a1>=n))
{
w=4;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*80));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*100));
if((a1<=m) && (a1>=n))
{
w=5;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*100));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*120));
if((a1<=m) && (a1>=n))
{
w=6;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*120));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*140));
if((a1<=m) && (a1>=n))
{
w=7;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*140));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*160));
if((a1<=m) && (a1>=n))
{
w=8;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*160));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*180));
if((a1<=m) && (a1>=n))
{
w=9;
}
}
else
{
m=(getmaxx()/2)+(120*cos((3.14/180.0)*180));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*200));
if((a1>=m) && (a1<=n))
{
w=10;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*200));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*220));
if((a1>=m) && (a1<=n))
{
w=11;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*220));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*240));
if((a1>=m) && (a1<=n))
{
w=12;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*240));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*260));
if((a1>=m) && (a1<=n))
{
w=13;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*260));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*280));
if((a1>=m) && (a1<=n))
{
w=14;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*280));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*300));
if((a1>=m) && (a1<=n))
{
w=15;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*300));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*320));
if((a1>=m) && (a1<=n))
{
w=16;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*320));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*340));
if((a1>=m) && (a1<=n))
{
w=17;
}
m=(getmaxx()/2)+(120*cos((3.14/180.0)*340));
n=(getmaxx()/2)+(120*cos((3.14/180.0)*360));
if((a1>=m) && (a1<=n))
{
w=18;
}
}
return w;
}

float bet()
{
float b;
float w;
char ch;
hidemousetext();
clrscr();
cleardevice();
setbkcolor(MAGENTA);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
setcolor(BLUE);
outtextxy(getmaxx()/2-300,getmaxy()/2-80,"Enter Amount in $ To Start The Bet With And Press Enter");
setcolor(RED);
setfillstyle(SOLID_FILL,WHITE);
bar(getmaxx()/2-100,getmaxy()/2-30,getmaxx()/2+100,getmaxy()/2+30);
gotoxy(38,15);
scanf("%f",&b);
rewind(fp2);
fprintf(fp2,"%f",b);
ch=getchar();
if(ch=='\n')
{
w=b;
}
sound(1500);
delay(100);
nosound();
return w;
}
int intro()
{
int j,w;
char ch;
clrscr();
cleardevice();
srand(time(NULL));
setbkcolor(YELLOW);
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
setcolor(RED);
outtextxy(getmaxx()/12,30,"KINDLY LEARN THE RULES OF BET BELOW!!!");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
setcolor(GREEN);
outtextxy(getmaxx()/20,80,"a) You must choose one among the two modes of bet:");
outtextxy(getmaxx()/10,100,"The easy mode and the difficult ones!!!");
setcolor(BLUE);
outtextxy(getmaxx()/20,120,"b) After choosing the mode,you must enter the amount");
outtextxy(getmaxx()/10,140,"of bet you wish to start with!!!");
setcolor(MAGENTA);
outtextxy(getmaxx()/20,160,"c) You must choose one among the numbers from 1 to 18");
outtextxy(getmaxx()/10,180,"on which you wish to keep the bet on!!!");
setcolor(CYAN);
outtextxy(getmaxx()/20,200,"d) Attaining the same number on the wheel as you chose,");


outtextxy(getmaxx()/10,220,"after the roll of wheel gives you victory,else a loss !!!");
setcolor(BROWN);
outtextxy(getmaxx()/20,240,"e) Victory refers to the doubling your amount on bet while");
outtextxy(getmaxx()/10,260,"loss refers to halving it,successively!!!");
setcolor(DARKGRAY);
outtextxy(getmaxx()/20,280,"f) Having amount on bet below $1 makes you lose the bet,i.e.");
outtextxy(getmaxx()/10,300,"The minimum limit of playing bet is $1!!!");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
delay(1000);
for(j=1;j<=15;j++)
{
sound(rand()%(3000-2000+1)+2000);
setcolor(rand()%13+1);
outtextxy(getmaxx()/2-150,getmaxy()/2+120,"PRESS ENTER TO CONTINUE!!!");
delay(100);
nosound();
}
ch=getchar();
if(ch=='\n')
{
delay(100);
sound(1500);
delay(100);
nosound();
w=1;
}
return w;
}








