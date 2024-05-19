#include<Windows.h>
#include<GL\glut.h>
#include<stdlib.h>
#include<time.h>
void init()
{
glClearColor(0.4, 0.5, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0, 800, 0.0, 600);
}
void rumah()
{
glClear(GL_COLOR_BUFFER_BIT); // Clear display window
// Warna random untuk rumah
srand(time(NULL));
float r = (float)rand() / RAND_MAX;
float g = (float)rand() / RAND_MAX;
float b = (float)rand() / RAND_MAX;
// Tembok
glColor3f(r, g, b);
glBegin(GL_POLYGON);
glVertex2i(200, 400);
glVertex2i(600, 400);
glVertex2i(600, 100);
glVertex2i(200, 100);
glEnd();
// Jendela
glColor3f(r - 0.2, g - 0.2, b - 0.2); // Warna yang sedikit lebih gelap untuk jendela
for (int i = 0; i < 3; ++i) {
glBegin(GL_POLYGON);
glVertex2i(250 + i * 100, 350);
glVertex2i(350 + i * 100, 350);
glVertex2i(350 + i * 100, 300);
glVertex2i(250 + i * 100, 300);
glEnd();
}
// Atap
glColor3ub(150, 75, 0);
glBegin(GL_POLYGON);
glVertex2i(200, 400);
glVertex2i(600, 400);
glVertex2i(400, 550);
glEnd();
// Pintu
glColor3f(r - 0.1, g - 0.1, b - 0.1); // Warna yang sedikit lebih gelap untuk pintu
glBegin(GL_POLYGON);
glVertex2i(350, 100);
glVertex2i(450, 100);
glVertex2i(450, 250);
glVertex2i(350, 250);
glEnd();
// Gagang pintu
glColor3f(0.3, 0.7, 0.9);
glPointSize(15);
glBegin(GL_POINTS);
glVertex2i(360, 175);
glEnd();
// Jalan
glColor3f(0.4, 0.4, 0.4);
glBegin(GL_POLYGON);
glVertex2i(200, 100);
glVertex2i(600, 100);
glVertex2i(600, 0);
glVertex2i(200, 0);
glEnd();
glFlush();
}
int main(int argc, char ** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(800, 600);
glutCreateWindow("Rayhan Al Farassy_Gambar Bebas");
init();
glutDisplayFunc(rumah);
glutMainLoop();
}

