#include <Windows.h>
#include <GL/glut.h>
#include <math.h>

void init()
{
    glClearColor(0.0, 0.0, 0.2, 0.0); // Warna latar belakang biru gelap untuk langit malam
    glMatrixMode(GL_PROJECTION); // Menetapkan mode matriks proyeksi
    gluOrtho2D(0.0, 800, 0.0, 600); // Mengatur sistem koordinat jendela
}

void satelit()
{
    glClear(GL_COLOR_BUFFER_BIT); // Menghapus layar tampilan

    // Bintang-bintang di langit malam
    glColor3f(1.0, 1.0, 1.0); // Warna putih untuk bintang
    glPointSize(2); // Mengatur ukuran titik
    glBegin(GL_POINTS);
    for (int i = 0; i < 1000; ++i) {
        float x = rand() % 800;
        float y = rand() % 600;
        glVertex2f(x, y);
    }
    glEnd();

    // Satelit - Menara (Silinder)
    glColor3f(0.8, 0.8, 0.8); // Warna abu-abu terang untuk menara
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
    float degInRad = i * 3.14159 / 180;
    glVertex2f(400 + cos(degInRad) * 8, 100 + sin(degInRad) * 200); // Menyesuaikan posisi dan ukuran sesuai kebutuhan
    }
    glEnd();
    
    // Tanah
    glColor3f(0.0, 0.4, 0.0); // Warna hijau gelap untuk tanah
    glBegin(GL_POLYGON);
    glVertex2i(0, 100); // Sudut kiri bawah
    glVertex2i(800, 100); // Sudut kanan bawah
    glVertex2i(800, 0); // Sudut kanan atas
    glVertex2i(0, 0); // Sudut kiri atas
    glEnd();

    // Satelit - Badan Utama (Bola)
    glColor3f(0.5, 0.5, 0.5); // Warna abu-abu untuk badan satelit
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(400 + cos(degInRad) * 150, 300 + sin(degInRad) * 80);
    }
    glEnd();

    // Satelit - Antena 1 (Silinder)
    glColor3f(0.8, 0.8, 0.8); // Warna abu-abu terang untuk antena
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(400 + cos(degInRad) * 10, 300 + sin(degInRad) * 120); // Menyesuaikan radius atau panjang sesuai kebutuhan
    }
    glEnd();

    // Satelit - Antena 2 (Silinder)
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159 / 180;
        glVertex2f(400 + cos(degInRad) * 150, 300 + sin(degInRad) * 70); // Menyesuaikan radius atau panjang sesuai kebutuhan
    }
    glEnd();

    // Satelit - Tiang (Segitiga)
    glColor3f(0.6, 0.6, 0.6); // Warna abu-abu terang untuk tiang
    glBegin(GL_TRIANGLES);
    glVertex2i(400, 400); // Titik puncak
    glVertex2i(390, 300); // Titik kiri bawah
    glVertex2i(410, 300); // Titik kanan bawah
    glEnd();

    // Satelit - Pengirim (Titik)
    glColor3f(1.0, 0.0, 0.0); // Warna merah untuk pengirim
    glBegin(GL_POINTS);
    glVertex2i(400, 420); // Posisi pengirim
    glEnd();
    

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rayhan Al Farassy: Antena Satelit");
    init();
    glutDisplayFunc(satelit);
    glutMainLoop();
    return 0;
}
