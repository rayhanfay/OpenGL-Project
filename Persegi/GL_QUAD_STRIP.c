#include <windows.h>
#include <gl/gl.h>
#include <GL/glut.h>
void disp(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_QUAD_STRIP);
glColor3ub(154,123,21);
glVertex2f(-0.5, -0.5);
glVertex2f(-0.5, 0.5);
glVertex2f(0.5, -0.5);
glVertex2f(0.5, 0.5);
glEnd();
glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitWindowSize (350, 350);
glutInitWindowPosition(0,0);
glutCreateWindow("Rayhan Al Farassy Membuat Persegi Menggunakan GL_QUAD_STRIP");
glutDisplayFunc(disp);
glutMainLoop();
return 0;
}
