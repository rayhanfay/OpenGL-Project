#include <windows.h>
#include <GL/glut.h>
#include <math.h>
const double PI = 3.14159265358979323846;
int radius = 50;
int jumlah_titik = 60;
int x_tengah = 250; // Koordinat x pusat window
int y_tengah = 250; // Koordinat y pusat window
int jumlah_lingkaran = 5; // Jumlah lingkaran yang akan digambar
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
// Gambar beberapa lingkaran
for (int j = 0; j < jumlah_lingkaran; j++)
{
int lingkaran_radius = radius + j * 20; // Setiap lingkaran memiliki radius yang berbeda
int lingkaran_x = x_tengah + (j * 70); // Jarak horizontal antara lingkaran
glColor3ub(25 + j * 20, 123 - j * 10, 44 + j * 15); // Warna lingkaran yang berbeda
glBegin(GL_LINE_LOOP);
for (int i = 0; i < jumlah_titik; i++)
{
float sudut = i * (2 * PI / jumlah_titik);
float x = lingkaran_x + lingkaran_radius * cos(sudut);
float y = y_tengah + lingkaran_radius * sin(sudut);
glVertex2f(x, y);
}
glEnd();
}
glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutCreateWindow("Rayhan Al Farassy Membuat Lingkaran");
gluOrtho2D(0, 500, 0, 500); // Mengatur sistem koordinat
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

