#include<iostream.h>

#include<graphics.h>

#include<conio.h>

/*TOP=0001, LEFT=1000, RIGHT=0100, BOTTOM=0010*/

int compOutCode(

double x,double y,

double xmin,double xmax,

double ymin,double ymax)

{

int code=0000;

if(y>ymax)

code+=0001;

else if(y<ymin)

code+=0010;

if(x>xmax)

code+=0100;

else if(x<xmin)

code+=1000;

 

 return code;

}

void cohen(

double x0,double y0,

double x1, double y1,

double xmin,double xmax,

double ymin,double ymax)

{

cout<<"Applying Cohen-Sutherlan Algorithm";

int outcode0,outcode1,outcodeout;

int acc=0,done=0;

outcode0=compOutCode(x0,y0,xmin,xmax,ymin,ymax);

outcode1=compOutCode(x1,y1,xmin,xmax,ymin,ymax);

do

{

 if(!(outcode0|outcode1))

 {

 acc=1;done=1;

 }

 else if(outcode0&outcode1)

 { done=1;

 }

 else{

  double x,y;

  outcodeout=outcode0?outcode0:outcode1;

  if(outcodeout&0001)

  {

  x=x0+(x1-x0)*(ymax-y0)/(y1-y0);

  y=ymax;

  cout<<"\nClipping Top!!!";

  }

  else if(outcodeout&0010)

  {

  x=x0+(x1-x0)*(ymin-y0)/(y1-y0);

  y=ymin;

  cout<<"\nClipping Bottom!!!";

  }

  else if(outcodeout&0100)

  {y=y0+(y1-y0)*(xmax-x0)/(x1-x0);

  x=xmax;

  cout<<"\nClipping Right";

  }

  else

  {y=y0+(y1-y0)*(xmin-x0)/(x1-x0);

  x=xmin;

  cout<<"\nClipping Left";

  }

  if(outcodeout==outcode0)

  {

  x0=x;y0=y;outcode0=compOutCode(x0,y0,xmin,xmax,ymin,ymax);

}

else

{

x1=x;y1=y;outcode1=compOutCode(x1,y1,xmin,xmax,ymin,ymax);

}

 }

}

while(done==0);

clrscr();

cout<<"After clipping window and line:";

rectangle(xmin,ymax,xmax,ymin);

line(x0,y0,x1,y1);

getch();

 return;

}

void main()

{

int i,gd=DETECT,gm;

int l,r,b,t;

initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

cout<<"Enter the coordinates of clipping window:\n";

cout<<"left: ";

cin>>l;

cout<<"bottom: ";

cin>>b;

cout<<"right: ";

cin>>r;

cout<<"top: ";

cin>>t;

int x0,x1,y0,y1;

cout<<"Enter the coordinates of original line:\n";

cout<<"x0: ";

cin>>x0;

cout<<"y0: ";

cin>>y0;

cout<<"x1: ";

cin>>x1;

cout<<"y1: ";

cin>>y1;

clrscr();

cout<<"Before clipping window and line:";

rectangle(l,t,r,b);

line(x0,y0,x1,y1);

 

 

getch();

cohen(x0,y0,x1,y1,l,r,b,t);

 return;

}