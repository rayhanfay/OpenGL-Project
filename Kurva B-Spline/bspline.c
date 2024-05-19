#include<GL/glut.h>
#include<GL/glut.h>
#include <Math.h>

void display(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (177, 129, 255);

	float i = 0.0;
	float t = 0.0;
	for(i=0.0; i<360; i+=45){
	    glRotatef(i, 0.0f, 0.0f, 1.0f);
	    glBegin(GL_LINE_STRIP);
	    for(t = -0.5; t<=0.5; t+=0.1){
	        /* x(t) = -1 + 2t; y(t) = 0 */
	        glVertex3f (t-0.5, t*t-0.25, 0.0);
	    }
	    
	    glEnd();
	}
    
    glFlush ();
}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA); 
	glutInitWindowSize(400,400); 
	glutInitWindowPosition(0,0); 
    glutCreateWindow("Kurva");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

