#include<Windows.h>
#include<GL\glut.h>
#include<stdlib.h>
#include<time.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define HOUSE_WIDTH 100
#define HOUSE_HEIGHT 100
#define HOUSE_GAP 20 // Jarak antara rumah
void init()
{
glClearColor(0.4, 0.5, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
}
void drawHouse(float x, float y)
{
// Warna random untuk rumah
float r = (float)rand() / RAND_MAX;
float g = (float)rand() / RAND_MAX;
float b = (float)rand() / RAND_MAX;
// Tembok
glColor3f(r, g, b);
glBegin(GL_POLYGON);
glVertex2f(x, y);
glVertex2f(x + HOUSE_WIDTH, y);
glVertex2f(x + HOUSE_WIDTH, y + HOUSE_HEIGHT);
glVertex2f(x, y + HOUSE_HEIGHT);
glEnd();
// Jendela
glColor3f(r - 0.2, g - 0.2, b - 0.2); // Warna yang sedikit lebih gelap untuk jendela
glBegin(GL_POLYGON);
glVertex2f(x + 20, y + 70);
glVertex2f(x + 40, y + 70);
glVertex2f(x + 40, y + 50);
glVertex2f(x + 20, y + 50);
glEnd();
// Atap
glColor3ub(150, 75, 0);
glBegin(GL_POLYGON);
glVertex2f(x, y + HOUSE_HEIGHT);
glVertex2f(x + HOUSE_WIDTH, y + HOUSE_HEIGHT);
glVertex2f(x + HOUSE_WIDTH / 2, y + HOUSE_HEIGHT + 50);
glEnd();
// Pintu
glColor3f(r - 0.1, g - 0.1, b - 0.1); // Warna yang sedikit lebih gelap untuk pintu
glBegin(GL_POLYGON);
glVertex2f(x + 30, y);
glVertex2f(x + 50, y);
glVertex2f(x + 50, y + 40);
glVertex2f(x + 30, y + 40);
glEnd();
// Gagang pintu
glColor3f(0.3, 0.7, 0.9);
glPointSize(5);
glBegin(GL_POINTS);
glVertex2f(x + 40, y + 20);
glEnd();
}
void drawHouses()
{
srand(time(NULL));
int numCols = WINDOW_WIDTH / (HOUSE_WIDTH + HOUSE_GAP);
int numRows = WINDOW_HEIGHT / (HOUSE_HEIGHT + HOUSE_GAP);
float startX = (WINDOW_WIDTH - numCols * HOUSE_WIDTH -
(numCols - 1) * HOUSE_GAP) / 2.0;
float startY = (WINDOW_HEIGHT - numRows * HOUSE_HEIGHT -
(numRows - 1) * HOUSE_GAP) / 2.0; for (int i = 0; i < numRows; ++i) { for (int j = 0; j < numCols; ++j) { float x = startX + j * (HOUSE_WIDTH + HOUSE_GAP); float y = startY + i * (HOUSE_HEIGHT + HOUSE_GAP); drawHouse(x, y);
}
}
glFlush();
}
int main(int argc, char ** argv)
{glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
glutCreateWindow("Rayhan Al Farassy_Gambar Bebas Looping");
init();
glutDisplayFunc(drawHouses);
glutMainLoop();
}

