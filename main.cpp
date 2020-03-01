#include <windows.h>
#include<string.h>
#include<stdarg.h>
#include<stdio.h>
#include <GL/glut.h>
static double x=0.0,x1=0.0,y1=0.1,z1=0.0,a1=0,y2=0,z2=0;
static float rx[100]={0}, ry[100]={0};
static double w1=0,w2=0,w3=0;
static bool transmit=false;
//static double move=-60;
//static bool seperate=false;

void stroke_output(GLfloat x, GLfloat y, const char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(-2.5, y, 0);
	glScaled(0.003, 0.005, 0.005);
	for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}
void waves(){

	glPushMatrix();
	glTranslatef(0,1,0);
	glScaled(0.05,0.5,0.1);
	glutSolidCube(0.5);
	glPopMatrix();


	glPushMatrix();
	glRotatef(-8,0,0,1);
	glTranslatef(0.01,1,0);
	glScaled(0.05,0.5,0.1);
	glutSolidCube(0.5);
	glPopMatrix();


	glPushMatrix();
	glRotatef(8,0,0,1);
	glTranslatef(-0.01,1,0);
	glScaled(0.05,0.6,0.1);
	glutSolidCube(0.5);
	glPopMatrix();

}

void stars1(){

int count = 0;
glPointSize(2.5);
	for(int j=0;j<100;j++)
	{   count++;
		for(int i=0;i<100;i++)
		{

			 rx[j]=rand()/500;
				 ry[i]=rand()/500;
            glBegin(GL_POINTS);
			glColor3f(1,1,1);


            if(count%2 == 0){
            glVertex3f(-6+rx[j],ry[i],-5);
            }
            else{
		glVertex3f(0.5+rx[j],ry[i]+0.5,-5);}
			glEnd();


		}
    }

}

void stars(){
int count = 0;
glPointSize(1.5);
	for(float s1=-5;s1<=500; s1+=1.0){
            count++;
		for(float s2=-6;s2<=6;s2+=1.0){

	glPushMatrix();
	glBegin(GL_POINTS);
	//if(!(s1<0 && s1 > -10)){
	if(count%2 == 0){
        	glVertex3f(s2+0.5,s1+0.5,0);
	}else{
		glVertex3f(s2,s1,0);
	}
	}
		}
 int count1 = 0;
	for(float s3=100;s3<=100; s3+=1.0){
            count1 ++;
		for(float s4=-6;s4<=6;s4+=1.0){
	glPushMatrix();
	glBegin(GL_POINTS);
		glVertex3f(s3,s4,0);


	glEnd();

	glPopMatrix();

	}

	}

stars1();
}

void satellite(){

	glPushMatrix();
	//glRotatef(60,1,0,0);

	//Core

	glPushMatrix();
	glColor3f(1,1,0);
	glTranslatef(0,2,0);
	glScaled(0.3,1,0.3);
	glRotatef(90,1,0,0);
    if(x<=6)
	glutSolidTorus(0.5,1,30,30);
	else
	glutSolidCube(1);
	glPopMatrix();

	// Solar Panel


	glPushMatrix();
	glColor3f(0.2,0.2,0.2);
	glTranslatef(1,2,0);

	if(x>=6){
		glScaled(4,1.5,0.1);
    }
	else
		glScaled(0,0,0);

	glRotatef(-20,1,0,0);
	glutSolidCube(0.5);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.2,0.2,0.2);
	glTranslatef(-1,2,0);
	if(x>=6){
		glScaled(4,1.5,0.1);
	}
	else
		glScaled(0,0,0);
	glRotatef(-20,1,0,0);
	glutSolidCube(0.5);
	glPopMatrix();


	glPopMatrix();

}

void rocket(){

	// Main top cone
	glPushMatrix();
	if(x>=5.5){
	glTranslatef(z2,-z2,z2);
	glRotatef(a1,0,1,1);
	}
	glPushMatrix();
	glTranslatef(0,2.5,0);
	glColor3f(1,0,0);
	glScaled(2.2 ,1.5,2.2);
	glRotatef(270,1,0,0);
	glutSolidCone(0.2,1,30,30);

	glPopMatrix();


	glPopMatrix();

	// Satelitte container
glPushMatrix();
if(x>=6.8){

glTranslatef(2,0,0);
glRotatef(x*40,0,1,0);


}
satellite();
glPopMatrix();
glPushMatrix();
if(x>=5){
glTranslatef(0,y2,y2);
glRotatef(a1,0,1,1);


}
    glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0,0.0,0);
	glScaled(0.3,4.3,0.3);
	glRotatef(90,1,0,0);
	glutSolidTorus(0.5,1,30,30);
	glPopMatrix();


    glPushMatrix();
	glTranslatef(0,-2.2,0);
	glColor3f(1.0,0.0,0.0);
	glScaled(3,1.5,3);
	glRotatef(270,1,0,0);
	glutSolidCone(0.2,1,30,30);
	glPopMatrix();

	glPopMatrix();


	// RightSide rocket
	glPushMatrix();
	glTranslatef(x1,-y1,z1);
	glRotatef(a1,0,1,1);

	glPushMatrix();
	glTranslatef(0.7,1,0);
	glColor3f(1.0,0.0,0.0);
	glScaled(1.5 ,1,1.5);
	glRotatef(270,1,0,0);
	glutSolidCone(0.2,1,30,30);
	glPopMatrix();


    glPushMatrix();
	glTranslatef(0.7,-0.2,0);
	glColor3f(1,1,1);
	glScaled(0.2,6.5,0.2);
	glRotatef(90,1,0,0);
	glutSolidTorus(0.2,1,30,30);
	glPopMatrix();



    glPushMatrix();
	glTranslatef(0.7,-2.0,0);
	glColor3f(1.0,0.0,0.0);
	glScaled(1.5,1,1.5);
	glRotatef(270,1,0,0);
	glutSolidCone(0.2,1,30,30);
	glPopMatrix();

	glPopMatrix();


	// LeftSide rocket

	glPushMatrix();
	glTranslatef(-x1,-y1,-z1);
	glRotatef(-a1,0,1,1);

	glPushMatrix();
	glTranslatef(-0.7,1,0);
	glColor3f(1.0,0.0,0.0);
	glScaled(1.5 ,1,1.5);
	glRotatef(270,1,0,0);
	glutSolidCone(0.2,1,30,30);
	glPopMatrix();


    glPushMatrix();
	glTranslatef(-0.7,-0.2,0);
	glColor3f(1,1,1);
	glScaled(0.2,6.5,0.2);
	glRotatef(90,1,0,0);
	glutSolidTorus(0.2,1,30,30);
	glPopMatrix();



    glPushMatrix();
	glTranslatef(-0.7,-2.0,0);
	glColor3f(1.0,0.0,0.0);
	glScaled(1.5,1,1.5);
	glRotatef(270,1,0,0);
	glutSolidCone(0.2,1,30,30);
	glPopMatrix();
	glPopMatrix();




}
// Draw rocket

void rocket(double ang)
{


   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);
    //glRotatef(ang,0.0f,1.0f,0.0f);


    glPushMatrix();

	if(ang<=2){
	glRotatef(ang*30,1,0,0);
		glTranslatef(0,-2+ang,0);
	}
	else{
	glRotatef(60,1,0,0);
		glTranslatef(0,0,0);
	}
	glScaled(0.5,0.5,0.5);
	rocket();
	glPopMatrix();

	//Earth

	glPushMatrix();
	glColor3f(0.3,0.3,1);
	//glColor3f(0.1,0.2,1);
	if(x>=6.5){
	glTranslatef(0,-18,-95);
	glRotatef(10*x,0,1,1);
	//glRotatef(ang,0.0f,1.0f,0.0f);

	}else
	{
        glTranslatef(0,-10-x,-10-15*x);
        glRotatef(40*x,0,1,1);
	}

	glutSolidSphere(10,100,100);

	glPopMatrix();

// Create Stars
	glPushMatrix();
	glColor3f(1,1,1);
	//glPointSize(1.5);
	//glTranslatef(0,-ang,0);
	stars();
	glPopMatrix();



	glFlush();
    glutSwapBuffers();
}


void satellite1(){

	glRotatef(60,1,0,0);
	//body
	glPushMatrix();
	glColor3f(1,1,0);
	glScaled(1,0.6,1);
	glTranslatef(3.0,0,0.0);
	glutSolidCube(0.4);

	glPopMatrix();

	//Solar Panels

	glPushMatrix();
	glColor3f(0.2,0.2,0.2);
	glTranslatef(3,0,0.0);
	//glRotatef(45,1,0,0);
	glScaled(3.7,0.0,1);
	glutSolidCube(0.4);
	glPopMatrix();

	/*glPushMatrix();
	glColor3f(0.2,0.1,0.1);
	glTranslatef(3.0,0,-0.4);
	glScaled(0.5,0.5,0.5);
	glutSolidSphere(0.3,50,50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2,0.2,0.1);
	glTranslatef(3.0,0,0.4);
	glScaled(0.4,0.4,0.3);
	glutSolidTorus(0.3,0.2,20,20);
	glPopMatrix();*/

}

void sat2(double ang)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-13.0f);
   	glRotatef(ang,0.0f,1.0f,0.0f);

	//earth

	glPushMatrix();

	glColor3f(0.3,0.5,1);
	//glScaled(0.8,0.04,0.8);
	//glTranslatef(0.0,0,0.0);
	glutSolidSphere(2.0,50,50);
	glPushMatrix();
	//glColor3f(0,0,1);

	if(transmit){
	//glRotatef(-25,0,0,1);
	glRotatef(-100,0,0,1);
	glTranslatef(-9.25,-1.6+w1,0);
	}else glTranslatef(1,20,3.3);
	waves();

	glPopMatrix();
    waves();
	glPopMatrix();


	satellite1();
	glPushMatrix();
	if(transmit){
	glRotatef(50,0.2,0.4,1);
	glTranslatef(2.8,3.2-w2,0);
	}else glTranslatef(1,20,3.3);
	waves();

	glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void P1()
{

    x+=0.01;
	if(x>=3){
		x1+=0.1;
		y1+=0.1;
		z1+=0.01;
		a1+=3;
	}

	if(x>5){
	y2-=0.1;

	}

	if(x>5.5){
	z2+=0.1;
	}

rocket(x);

  }
void S1()
{

	x-=0.07;
	if(transmit)
	{
	if(w1<=4.2)
	w1+=0.01;

	if(w1>=2.5 && w2<=6.9)
	w2+=0.01;

	if(w1>=2.5 && w3<=5)
	w3+=0.01;
	}
	glPushMatrix();

	glPopMatrix();
	sat2(x);
    waves();



  }

void doInit()
{

	/* Background and foreground color */
    glClearColor(0.0,0.0,0.0,0);
       glViewport(0,0,640,480);

	/* Select the projection matrix and reset it then
     setup our view perspective */

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);

    /* Select the modelview matrix, which we alter with rotatef() */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearDepth(2.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-13.0f);
	const char* PP = "P-->Launch the Rocket";

    stroke_output (-3.0, 1.7, PP);
    stroke_output (-3.0, 0.9, "s-->Satelite rotation around earth");

	GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
	GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
	GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={30.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
	GLfloat light_position3[]={0.0f,5.0f,0.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);


	glEnable(GL_COLOR_MATERIAL);

	glFlush();
	glutSwapBuffers();

}

void menu(int id)
{
	switch(id)
	{
	case 1:glutIdleFunc(P1);
		break;
	case 2:glutIdleFunc(S1);
		break;
	default:exit(0);
		break;
   	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void mykey(unsigned char key,int x,int y)
{

	if(key=='p')
	{
		glutIdleFunc(P1);
	}
    else if(key=='s')
    {
       glutIdleFunc(S1);
    }
    if(key=='t')

	{	transmit=!transmit;
		if(!transmit)
		{
			w1=0;
			w2=0;
			w3=0;

		}
		glutIdleFunc(S1);
	}


}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("rocket");
    glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutCreateMenu(menu);
	glutKeyboardFunc(mykey);
    glutAddMenuEntry("Launch   'p'",1);
    glutAddMenuEntry("Rotate       's'",2);
    glutAddMenuEntry("Quit            'q'",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	doInit();
    glutMainLoop();
	return 0;
}
