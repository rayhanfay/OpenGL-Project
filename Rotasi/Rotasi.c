#include <GL/glut.h>
#include <math.h>

// Fungsi untuk menginisialisasi OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// Fungsi untuk menggambar panah tujuh sisi
void drawArrow() {
    // Koordinat titik-titik panah, panjang batang dipersingkat
    GLfloat vertices[][2] = {
        {0.0, 0.5},  // Puncak panah tetap sama
        {0.1, 0.4},
        {0.05, 0.4},
        {0.05, -0.1},  // Batang panah diperpendek
        {-0.05, -0.1},  // Batang panah diperpendek
        {-0.05, 0.4},
        {-0.1, 0.4}
    };

    // Sudut rotasi 90 derajat dalam radian
    GLfloat angle = M_PI / 1;
    GLfloat cosAngle = cos(angle);
    GLfloat sinAngle = sin(angle);

    glClear(GL_COLOR_BUFFER_BIT);

    // Menggambar panah asli tanpa rotasi (warna RGB(177,129,255) / ungu)
    glColor3f(177.0 / 255.0, 129.0 / 255.0, 255.0 / 255.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 7; i++) {
        int next = (i + 1) % 7;
        glVertex2f(vertices[i][0], vertices[i][1]);
        glVertex2f(vertices[next][0], vertices[next][1]);
    }
    glEnd();

    // Menggambar panah dengan rotasi 90 derajat (warna RGB(119,212,228) / biru muda)
    glColor3f(119.0 / 255.0, 212.0 / 255.0, 228.0 / 255.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 7; i++) {
        int next = (i + 1) % 7;

        // Rotasi titik-titik
        GLfloat x1 = vertices[i][0] * cosAngle - vertices[i][1] * sinAngle;
        GLfloat y1 = vertices[i][0] * sinAngle + vertices[i][1] * cosAngle;
        GLfloat x2 = vertices[next][0] * cosAngle - vertices[next][1] * sinAngle;
        GLfloat y2 = vertices[next][0] * sinAngle + vertices[next][1] * cosAngle;

        // Menggambar garis antar titik
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();

    glFlush();
}

// Fungsi untuk menggambar (dipanggil oleh GLUT)
void draw() {
    drawArrow();
}

// Fungsi utama
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tugas7_Rayhan Al Farassy_2207135776");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

