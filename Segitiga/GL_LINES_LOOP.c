#include <windows.h>
#include <gl/gl.h>
#include <GL/glut.h>
void disp(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
glColor3ub(34,223,21);
glVertex2f(-0.5,-0.5);
glVertex2f(0.5,-0.5);
glVertex2f(0.0,0.5);
glEnd();
glFlush();
}
int main(int argc, char**argv)
{
glutInit(&argc, argv);
glutInitWindowSize(350,350);
glutInitWindowPosition(0,0);
glutCreateWindow("Segitiga");
glutDisplayFunc(disp);
glutMainLoop();
return 0;
}

