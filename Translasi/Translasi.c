#include<GL/glut.h>
#include<GL/glut.h>

float x = 0.2;
float y = 0.2;

void segitiga()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.3,-0.3);
	glVertex2f(0.3,-0.3);
	glVertex2f(0.0,0.2);
	
	glEnd();
	
	glRotatef(30.0, 0.0, 0.0, 1.0);
	glColor3f(1,1,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.3+x,-0.3+y);
	glVertex2f(0.3+x,-0.3+y);
	glVertex2f(0.0+x,0.2+y);
	
	glEnd();
	
	glFlush();
	glutSwapBuffers();
	
}

int main (int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rotasi Segitiga");
	glutDisplayFunc(segitiga);
	glutMainLoop();
}

