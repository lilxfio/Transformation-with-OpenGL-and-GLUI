#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL\glut.h>
#include <GL/glui.h>

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	main_window = glutCreateWindow("Viewing Transformation");
	gluOrtho2D(-WINDOW_WIDTH/2, WINDOW_WIDTH/2, -WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);

	init_val();
	init_glui();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);


	glutMainLoop();
	
	return 0;
}