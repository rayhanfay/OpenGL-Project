#include <GL/glut.h>
#include <math.h>
#define DEG2RAD 3.14159 / 180.0
#define STEP_ANGLE 10
void DrawEllipsePoints(float centerX, float centerY, float radiusX,
float radiusY, float angle)
{
if (angle >= 360)
return;
float rad = angle * DEG2RAD;
float x = centerX + radiusX * cos(rad);
float y = centerY + radiusY * sin(rad);
glVertex2f(x, y);
DrawEllipsePoints(centerX, centerY, radiusX, radiusY, angle +
STEP_ANGLE);
}
void DrawEllipse(float centerX, float centerY, float radiusX, float
radiusY)
{
glBegin(GL_POLYGON);
DrawEllipsePoints(centerX, centerY, radiusX, radiusY, 0);
glEnd();
}
void elips()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3ub(55, 128, 229);
DrawEllipse(0.0, 0.0, 0.5, 0.8);
glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
glutInitWindowSize(600, 600);
glutInitWindowPosition(0, 0);
glutCreateWindow("Rayhan Al Farassy Membuat Elips");
glutDisplayFunc(elips);
glClearColor(0.0, 0.0, 0.0, 1.0);
glutMainLoop();
return 0;
}

