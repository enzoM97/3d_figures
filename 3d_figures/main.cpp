#include "GL/freeglut.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;

//Initialize OpenGL 
void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// set background color to black and opaque
	glClearDepth(1.0f);						// set background depth to farthest
	glEnable(GL_DEPTH_TEST);				// enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);					// set the type of depth-test
	glShadeModel(GL_SMOOTH);				// enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// nice perspective corrections
}

void drawColoredTriangle(void)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);	glVertex3f(-0.6, -0.75, 0.5);
	glColor3f(0.0, 1.0, 0.0);	glVertex3f(0.6, -0.75, 0.0);
	glColor3f(0.0, 0.0, 1.0);	glVertex3f(0.0, 0.75, 0.0);
	glEnd();
}

void drawWireCube(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glColor3f(0.5f, 0.5f, 0.5f);
	glutWireCube(0.5);

	glFlush();
}

void drawWireCone(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor3f(0.5f, 0.5f, 0.5f);
	glutWireCone(1, 1, 10, 10);

	glFlush();
}

void drawTeapot(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.5f, 0.5f, 0.5f);
	glutWireTeapot(0.5);
	glBegin(GL_LINES);
	// axis1
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	// axis2
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	// axis3
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 2.0f);
	glEnd();

	glFlush();
}

void drawWireTorus(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0f, 0.5f, 0.0f);
	glutWireTorus(0.3, 0.5, 10, 10);
	
	glFlush();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 4.0 / 3.0, 1, 40);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //inicializa la libreria de glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);//selecciona el RGB y single buffering
	glutInitWindowSize(512, 512);//fija el tamanho de la ventana
	glutInitWindowPosition(400, 150);//fija la posicion de la ventana
	glutCreateWindow("3d figures");//crea la ventana con el nombre							
	//Llamar a la funcion init
	init();
	//declara los callbacks
	glutDisplayFunc(drawWireCone);
	glutReshapeFunc(reshape);
	//entra en el loop de reconocimientos de eventos
	glutMainLoop();
	return 0;
}
