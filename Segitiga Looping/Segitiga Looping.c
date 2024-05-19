#include <Windows.h>
#include <GL/glut.h>
#include <stdlib.h>
void init()
{
glClearColor(0.4, 0.5, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0, 800, 0.0, 600);
}
void gunung()
{
glClear(GL_COLOR_BUFFER_BIT); // Clear display window
// Jumlah segitiga dan warna awal
int jumlahSegitiga = 10;
// Perubahan warna
float perubahanWarna = 0.1 / jumlahSegitiga;
for (int i = 0; i < jumlahSegitiga; ++i) {
// Segitiga gunung
glColor3f(111,111,111);
glBegin(GL_TRIANGLES);
glVertex2i(i * 80, 0);
glVertex2i(i * 80 + 40, 300);
glVertex2i(i * 80 + 80, 0);
glEnd();
}
glFlush();
}
int main(int argc, char ** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(800, 600);
glutCreateWindow("Gunung Rapi");
init();
glutDisplayFunc(gunung);
glutMainLoop();
}
