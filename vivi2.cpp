#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

clock_t start,end;
int flag=0;
void *currentfont;
int score=0;
int count;
float i=0.0;
int j=0;
float k1=0.0;
float xt=1.0,yt=1.0;            // interactive Keyboard
float x = 1.0,y = 1.0,z=1.0;    // For Movement
float angle =0;                                                       // For Function animation
float Autorun = 0.0;  
int t;  
int df=10;      
float ex=0.0;                       // For Movement Autorun
void setFont(void *font)
{
	currentfont=font;
}
void drawstring(float x1,float y1,float z1,char *string)
{
	char *c;
	int len = (int) strlen(string);
	int i;
	glRasterPos3f(x1,y1,z1);
    for(i = 0;i<len;i++)
	{
	glColor3f(0.0,0.0,0.0);
	glutBitmapCharacter(currentfont,string[i]);
	}
}
void output(int x, int y, char *string)
{
    int len, i;
	glRasterPos2f(x,y);
    len=(int) strlen(string);
    for (i = 0; i < len; i++)
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	}
}
void bubble1()
{

for(j=25;j<=400;j+=100) 
{
glColor3f(1,1,1);       // front screen bubble
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+4*cos(i),0+4*sin(i));
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+4*cos(i),-50+4*sin(i));
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+4*cos(i),-100+4*sin(i));
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+4*cos(i),-150+4*sin(i));
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+4*cos(i),-200+4*sin(i));
glEnd();
}
  
}
void bubble()
{

for(j=25;j<=400;j+=100) 
{
glColor3f(1,1,1);       //aqua bubble
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+3*cos(i),0+3*sin(i));
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+2.5*cos(i),-50+2.5*sin(i));
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+2*cos(i),-100+2*sin(i));
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+1.5*cos(i),-150+1.5*sin(i));
glEnd();
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(j+1*cos(i),-200+1*sin(i));
glEnd();
}
}
void frontscreen()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(100,350.0,0.0,"GOPALAN COLLEGE OF ENGINEERING AND MANAGEMENT");
glColor3f(0.7,0,1);
drawstring(100,310,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
glColor3f(1,0.5,0);
drawstring(150,250,0.0,"A MINI PROJECT ON");
glBegin(GL_LINES);
glVertex2f(150,248);
glVertex2f(150,248);
glEnd();
glColor3f(1,0,0);
drawstring(155,230,0.0,"\"AQUA MANIA\"");
glColor3f(1,0.5,0);
drawstring(170,180,0.0,"BY:");
glBegin(GL_LINES);
glVertex2f(170,178);
glVertex2f(179,178);
glEnd();
glColor3f(0.074,0.349,0.011);
drawstring(150,160,0.0,"VIDYASHREE B(1GD17CS047)");
glColor3f(0.074,0.349,0.011);
drawstring(145,140,0.0,"VIJAYALAKSHMI V U(1GD17CS048)");
glColor3f(1,0.5,0);
drawstring(170,100,0.0,"GUIDE:");
glBegin(GL_LINES);
glVertex2f(170,98);
glVertex2f(190,98);
glEnd();
glColor3f(0.074,0.349,0.011);
drawstring(160,80,0.0,"V N MANJU");
drawstring(150,50,0.0,"PRESS ENTER TO START");
glPushMatrix();
glTranslated(0.0,k1,0.0);
bubble1();
glPushMatrix();
glTranslated(180,-20,0);
bubble1();
glPopMatrix();
glPopMatrix();
if(k1<=550)
k1 += 0.15;
else
k1=0.0;
k1+=0.06;
glutSwapBuffers();
glFlush();
}
void octo(){
	glColor3f(0,0,0.9);       
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(100+10*cos(i),100+10*sin(i));
glEnd();
glColor3f(0,0,0.9);                                                    //obstacle2
glBegin(GL_POLYGON);
glVertex2f(100,100);
glVertex2f(120,90);
glVertex2f(110,100);
glVertex2f(120,110);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1,1,1); 
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(96+2*cos(i),99+2*sin(i));
glEnd();
glColor3f(0,0,0); 
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(96+0.8*cos(i),99+0.8*sin(i));
glEnd();
}
void sfish(){
	glPushMatrix();
	glTranslatef(ex,0,0);
	glPushMatrix();
	octo();
	glTranslatef(200,200,0);
	octo();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(150,150,0);
	octo();
	glPopMatrix();
	glPushMatrix();
	glTranslated(290,50,0);
	octo();
	glPopMatrix();
	glPushMatrix();
	glTranslated(30,350,0);
	octo();
	glPopMatrix();
	glPopMatrix();
	if(ex>=-400){
		ex-=0.5;
	}
	else{
		ex=350.0;
		ex-=0.05;
	}
}
void animation(void)
{
 if(angle>=0 && angle<10)
angle = angle+0.5;
 else angle = 0;
 glutPostRedisplay();
}
void Auto(void)
{
if(Autorun<=0 && Autorun>350)
Autorun = Autorun+0.05;
else Autorun = 0.1;
glutPostRedisplay();
}  
void settings(void)
{
glClearColor(0.5,1.0,1.0,1.0);
glPointSize(5.0);
glLineWidth(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,400,0,400);
}
void instructions()
{
  glClear(GL_COLOR_BUFFER_BIT);
bgcolor();
glColor3f(1.0,0.5,0.0);
output(150,345,"INSTRUCTIONS:");
glBegin(GL_LINES);
glVertex2f(150,340);
glVertex2f(200,340);
glEnd();
glColor3d(0.33,0.89,0.55);
glBegin(GL_POLYGON);
glVertex2d(100,130);
glVertex2d(100,300);
glVertex2d(350,300);
glVertex2d(350,130);
glEnd();
glColor3d(1.0,0.0,0.0);
  output(120,260,"> To move the FISH use the following keys");
  output(120,240,"> *a->backward  *d->forward  *w->up *s->down..");
  output(120,220,"> FIND THE WAY TO MOVE THE FISH THROUGH GARBAGE");
  output(120,200,"> YOU WILL HAVE TO HURRY AS YOU HAVE LIMITED TIME");
  output(120,180,"> Press ESC to go to main menu");
   glFlush();
}
void startscreen()
{
glClear(GL_COLOR_BUFFER_BIT);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
bgcolor();
glBegin(GL_POLYGON);
glVertex2d(100-2,130-2);
glVertex2d(100-2,250+2);
glVertex2d(300+2,250+2);
glVertex2d(300+2,130-2);
glEnd();
glColor3d(0.33,0.89,0.55);
glBegin(GL_POLYGON);
glVertex2d(100,130);
glVertex2d(100,250);
glVertex2d(300,250);
glVertex2d(300,130);
glEnd();
glColor3f(0.678,0.10,0.10);
output(120,230,"WELCOME TO THE AQUA GAME!!");
output(135,210,"MAIN MENU");
output(150,190,"1.NEW GAME");
output(150,170,"2.INSTRUCTIONS");
output(150,150,"3.QUIT");
glFlush();
}
void bgcolor()
{
glBegin(GL_POLYGON);
glColor3f(0.258,0.325,0.956);
glVertex3f(-400.0, -400.0, 0);
glColor3f(0.258,0.325,0.956);
glVertex3f(400.0, -400.0, 0);
glColor3f(0.250,0.878,0.815);
glVertex3f(400.0, 400.0, 0.0);
glColor3f(0.250,0.878,0.815);
glVertex3f(-400.0, 400.0, 0);
glEnd();
}
void stones()
{
glBegin(GL_POLYGON);              //stone1
glColor3f(0.228,0.5,0.003);
glVertex3f(0.0, 0.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(10.0, 20.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(30.0, 28.0, 0.0);
glColor3f(0.717,0.352,0.054);
glVertex3f(50.0, 20.0, 0);
glColor3f(0.200,0.094,0.000);
glVertex3f(60.0, 0.0, 0);
glEnd();

glBegin(GL_POLYGON);                //stone2
glColor3f(0.278,0.125,0.003);
glVertex3f(60.0, 0.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(80.0, 20.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(140.0, 40.0, 0.0);
glColor3f(0.717,0.352,0.054);
glVertex3f(180.0, 30.0, 0);
glColor3f(0.600,0.294,0.030);
glVertex3f(190.0, 20.0, 0.0);
glColor3f(0.200,0.094,0.000);
glVertex3f(210.0, 0.0, 0);
glEnd();

glBegin(GL_POLYGON);              //stone3
glColor3f(0.278,0.125,0.003);
glVertex3f(210.0, 0.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(215.0, 10.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(230.0, 15.0, 0);
glColor3f(0.278,0.125,0.003);
glVertex3f(245.0, 8.0, 0.0);
glColor3f(0.200,0.094,0.000);
glVertex3f(255.0, 0.0, 0);
glEnd();

glBegin(GL_POLYGON);            //stone4
glColor3f(0.278,0.125,0.003);
glVertex3f(255.0, 0.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(260.0, 10.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(275.0, 15.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(290.0, 8.0, 0.0);
glColor3f(0.200,0.094,0.000);
glVertex3f(300.0, 0.0, 0);
glEnd();

glBegin(GL_POLYGON);            //stone5
glColor3f(0.278,0.125,0.003);
glVertex3f(350.0, 0.0, 0);
glColor3f(0.717,0.352,0.054);
glVertex3f(370.0, 40.0, 0);
glEnd();

}
void fish()
{
glPushMatrix();
glPushMatrix();
glRotatef(angle,0.0,0.0,0.0);
glTranslatef(Autorun,0.0,0.0);
glTranslatef(xt,yt,0.0);               //For Move    NEWS/QDZC  each Position.

glBegin(GL_POLYGON);                                                 // draw body
glColor3f(1.000,0.0,0.498);
glVertex2i(20-5,200-5);
glColor3f(0.298,0.000,0.600);
glVertex2i(70-5,180-5);
glColor3f(1.000,0.0,0.498);
glVertex2i(80-5,205-5);
glColor3f(0.298,0.000,0.600);
glVertex2i(65-5,230-5);
glEnd();
glPushMatrix();
glRotatef(angle,0.0,0.0,0.0);
glColor3f(1,1,1);       
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(62+2*cos(i),205+2*sin(i));
glEnd();
glColor3f(0,0,0); 
glBegin(GL_POLYGON);
for(i=0;i<2*3.14;i+=0.5)
glVertex2f(62+0.8*cos(i),205+0.8*sin(i));
glEnd();

glBegin(GL_POLYGON);                                       //draw tail
glColor3f(0.298,0.000,0.600);
glVertex2i(15-5,200-5);
glColor3f(1.000,0.0,0.498);
glVertex2i(10-5,180-5);
glColor3f(0.298,0.000,0.600);
glVertex2i(20-5,200-5);
glColor3f(0.298,0.000,0.600);
glVertex2i(10-5,220-5);
glEnd();

  glBegin(GL_POLYGON);                          //draw Top Key
glColor3f(1.0,0.0,0.0);
glVertex2i(27-5,204-5);
glVertex2i(65-5,230-5);
glVertex2i(60-5,240-5);
glEnd();

glBegin(GL_POLYGON);                          //draw Buttom Key
glVertex2i(65-5,182-5);
glVertex2i(70-5,180-5);
glVertex2i(60-5,200-5);
glEnd();
glPopMatrix();
glPopMatrix();
glPopMatrix();
}
void grass()
{
glColor3f(0,0.8,0);                           //grass3
glBegin(GL_POLYGON);
glColor3f(0.074,0.349,0.011);
glVertex2f(340+10,0);
glColor3f(0.074,0.349,0.011);
glVertex2f(330+10,20);
glColor3f(0.380,0.878,0.094);
glVertex2f(350+10,10);
glColor3f(0.380,0.878,0.094);
glVertex2f(350+10,50);
glColor3f(0.380,0.878,0.094);
glVertex2f(360+10,10);
glColor3f(0.380,0.878,0.094);
glVertex2f(370+10,20);
glColor3f(0.380,0.878,0.094);
glVertex2f(380,40);
glVertex2f(380,0);
glEnd();

glColor3f(0,0.8,0);                           //grass1
glBegin(GL_POLYGON);
glColor3f(0.074,0.349,0.011);
glVertex2f(10+10,0);
glColor3f(0.074,0.349,0.011);
glVertex2f(0+10,20);
glColor3f(0.074,0.349,0.011);
glVertex2f(20+10,10);
glColor3f(0.380,0.878,0.094);
glVertex2f(20+10,50);
glColor3f(0.380,0.878,0.094);
glVertex2f(30+10,10);
glColor3f(0.380,0.878,0.094);
glVertex2f(40+10,20);
glVertex2f(40,0);
glEnd();

    glColor3f(0,0.8,0);                           //grass2
glBegin(GL_POLYGON);
glColor3f(0.074,0.349,0.011);
glVertex2f(340-150,0);
glColor3f(0.074,0.349,0.011);
glVertex2f(330-150,20);
glColor3f(0.074,0.349,0.011);
glVertex2f(350-150,10);
glColor3f(0.380,0.878,0.094);
glVertex2f(350-150,50);
glColor3f(0.380,0.878,0.094);
glVertex2f(360-150,10);
glColor3f(0.380,0.878,0.094);
glVertex2f(370-150,20);
glColor3f(0.380,0.878,0.094);
glVertex2f(380-150,40);
glVertex2f(380-150,0);
glEnd();
}
void bubbles()
{
glPushMatrix();
glTranslated(0.0,k1,0.0);
bubble();
glPushMatrix();
    glTranslated(180,-20,0);
bubble();
glPopMatrix();
glPopMatrix();
if(k1<=550)
k1 += 0.05;
else
k1=0.0;
k1+=0.03;
}
void Display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
bgcolor();
stones();
fish();
sfish();
grass();
bubbles();
glutSwapBuffers();
glFlush();
}
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
  if(df==10)
    frontscreen();
  else if(df==0)
    startscreen();
  else if(df==1)
    instructions();
  else if(df==2)
    Display();
 /* else if(flag==1)
    winscreen(); */
glutSwapBuffers();
glFlush();
}
void keyboard(GLubyte key, int x, int y)   // For keyboard interactive
{
switch ( key )
{
case 13:if(df==10) //Ascii of 'enter' key is 13
     df=0;
    break;
case '2':             //instruction page
    if(df==0)
     df=1;
     break;
case 27:            //escape back to stsrtscreen
    if(df==1)
     df=0;
    break;
case '1':         //new game
    if(df==0)
     df=2;
    break;
case '3':          //quit the game
    exit(0);
    break;
case 'd': 
    if(xt>=350)
	{
		xt=0;
		xt+=2.0;
	}           
	else                    //forward
 xt=xt+2.0;
glutPostRedisplay();
break;
case 'a':                          //backward
   if(xt>=0)      
   {
	xt -= 2.0;
	score-=1;
   }   
glColor3f(1.0,0.0,0.0);
glutPostRedisplay();
break;
case 's':   //down
	if(yt>=-175)  
	{
	  yt -= 2.0;
	  score+=1; 
	}                      
glColor3f(0.0,0.0,0.0);
glutPostRedisplay();
break;
case 'w':                     //up
	if(yt<=175) 
	{
	yt += 2.0;
	score+=1;
	}     
glColor3f(0.0,0.0,1.0);
glutPostRedisplay();
break;
case 'e':                      //right up
  if(xt<=325 && yt<=175)
  {
	xt += 2.0;
	yt += 2.0;
	score+=1;
  }
glColor3f(1.0,0.0,1.0);
glutPostRedisplay();
break;
case 'q': //left up
	if(xt>=0 && yt<=175)
	{
	xt -= 2.0;
    yt += 2.0;
    score-=1;
	}
glColor3f(0.0,1.0,1.0);
glutPostRedisplay();
break;
case 'c': //right down 
    if(xt<=325 && yt>=-175)
	{
     xt += 2.0;
     yt -= 2.0;
     score+=1;
	}
glColor3f(1.0,0.0,1.0);
glutPostRedisplay();
break;
case 'z': //left down
	if(xt>=0 && yt>=-175)
	{
	xt -= 2.0;
	yt -= 2.0;
	score-=1;
	}
glColor3f(0.0,0.0,1.0);
glutPostRedisplay();
break;
default:
break;
}
}
int main(int a,char ** b)
{
glutInit(&a,b);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);   //200 Lelt 50 Height
glutInitWindowSize(400,400);
glutCreateWindow("Aqua Mania");
settings();
glutDisplayFunc(myDisplay);
glutIdleFunc(animation);
glutIdleFunc(Auto);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
