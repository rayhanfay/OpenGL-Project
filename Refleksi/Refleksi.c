#include <GL/glut.h>
#include <math.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void drawCoordinate() {
    // Draw the Cartesian coordinate system
    glColor3f(1.0, 1.0, 1.0); // White
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
}

void drawArrow(GLfloat (*vertices)[2], int numVertices, GLfloat colorR, GLfloat colorG, GLfloat colorB) {
    // Function to draw an arrow with specified coordinates and color

    glColor3f(colorR / 255.0, colorG / 255.0, colorB / 255.0); // Convert to normalized color values
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
}

void drawReflectedArrow(GLfloat (*vertices)[2], int numVertices, GLfloat colorR, GLfloat colorG, GLfloat colorB) {
    // Function to draw a reflected arrow with specified coordinates and color

    glColor3f(colorR / 255.0, colorG / 255.0, colorB / 255.0); // Convert to normalized color values
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; i++) {
        // Reflect over x-axis and y-axis
        glVertex2f(-vertices[i][0], -vertices[i][1]); 
    }
    glEnd();
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCoordinate();

    // Original arrow (orange)
    GLfloat originalVertices[][2] = {
        {-0.5, -0.2},
        {-0.6, -0.3},
        {-0.55, -0.3},
        {-0.55, -0.7},
        {-0.45, -0.7},
        {-0.45, -0.3},
        {-0.4, -0.3}
    };
    drawArrow(originalVertices, 7, 254, 197, 77); // Original arrow color (254, 197, 77)

    // Reflected arrow (blue)
    GLfloat reflectedVertices[][2] = {
        {-0.5, -0.2},
        {-0.6, -0.3},
        {-0.55, -0.3},
        {-0.55, -0.7},
        {-0.45, -0.7},
        {-0.45, -0.3},
        {-0.4, -0.3}
    };
    drawReflectedArrow(reflectedVertices, 7, 49, 91, 185); // Reflected arrow color (49, 91, 185)

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tugas8_Rayhan Al Farassy");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

