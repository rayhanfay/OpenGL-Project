#include <GL/glut.h>
#include <math.h>

GLfloat ctrlPoints[4][3] = {
    {-0.9, -0.5, 0.0},  // Titik kontrol pertama
    {-0.3, 0.7, 0.0},   // Titik kontrol kedua
    {0.3, -0.7, 0.0},   // Titik kontrol ketiga
    {0.9, -0.5, 0.0}    // Titik kontrol keempat
};

int windowWidth = 800;
int windowHeight = 600;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawControlPoints() {
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++)
        glVertex3fv(ctrlPoints[i]);
    glEnd();
}

void drawBezierCurve() {
    glColor3ub(254, 197, 77);
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    for (GLfloat t = 0.0; t <= 1.0; t += 0.01) {
        GLfloat p[3] = {0.0, 0.0, 0.0};
        for (int i = 0; i < 4; i++) {
            GLfloat blend = pow(1.0 - t, 3 - i) * pow(t, i);
            for (int j = 0; j < 3; j++)
                p[j] += ctrlPoints[i][j] * blend;
        }
        glVertex3fv(p);
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawControlPoints();
    drawBezierCurve();
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    GLfloat posX = (2.0 * x) / windowWidth - 1.0;
    GLfloat posY = 1.0 - (2.0 * y) / windowHeight;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Update the first control point
        ctrlPoints[0][0] = posX;
        ctrlPoints[0][1] = posY;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Update the fourth control point
        ctrlPoints[3][0] = posX;
        ctrlPoints[3][1] = posY;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Kurva Bezier 4 Titik Kontrol");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

