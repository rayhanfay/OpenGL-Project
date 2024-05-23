#include <GL/glut.h>
#include <math.h>

// Define Pi for rotation calculations
#define PI 3.14159265

// Function to apply shear transformation to a point
void shearTransform(GLfloat x, GLfloat y, GLfloat shearX, GLfloat shearY, GLfloat *shearedX, GLfloat *shearedY) {
    *shearedX = x + shearX * y;
    *shearedY = y + shearY * x;
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
}

void drawCustomShape() {
    // Define the coordinates of the custom shape
    GLfloat vertices[][2] = {
        {-0.5, 0.5}, {0.0, 0.9}, {0.5, 0.5}, {0.9, 0.0},
        {0.5, -0.5}, {0.0, -0.9}, {-0.5, -0.5}, {-0.9, 0.0}
    };

    // Define the shear transformation factors
    GLfloat shearX = 0.3; // Shear factor for x-direction
    GLfloat shearY = 0.2; // Shear factor for y-direction

    // Apply shear transformation to each vertex and draw the shape
    glBegin(GL_POLYGON);
    for (int i = 0; i < 8; ++i) {
        GLfloat x = vertices[i][0];
        GLfloat y = vertices[i][1];
        GLfloat shearedX, shearedY;
        shearTransform(x, y, shearX, shearY, &shearedX, &shearedY);
        glVertex2f(shearedX, shearedY);
    }
    glEnd();
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    drawCustomShape();
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

