#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <ctime>
#include <math.h>

#define PI 3.14159265

using namespace std;

int rise = 5;

void drawSun(int x,int y, int si,int ap)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < ap; i++)
	{
		double ang = PI * 2 / ap * i;
		glVertex2d(si * sin(ang) + x, si * cos(ang) + y);
	}
	glEnd();
}


static GLfloat colorA[] = {
					0.0f, 1.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 1.0f, 0.0f,

					0.0f, 1.0f, 1.0f,
					0.0f, 1.0f, 1.0f,
					0.0f, 1.0f, 1.0f,
					0.0f, 1.0f, 1.0f,

					1.0f, 1.0f, 1.0f,

					0.7f, 0.5f, 0.0f,
					0.7f, 0.5f, 0.0f,
					0.7f, 0.5f, 0.0f,
					0.7f, 0.5f, 0.0f,

					0.7f, 0.5f, 0.0f,
					0.7f, 0.5f, 0.0f,
					0.7f, 0.5f, 0.0f,

};


static GLfloat colorB[] = {
					0.0f, 0.5f, 0.0f,
					0.0f, 0.5f, 0.0f,
					0.0f, 0.5f, 0.0f,
					0.0f, 0.5f, 0.0f,

					0.0f, 0.0f, 0.2f,
					0.0f, 0.0f, 0.2f,
					0.0f, 0.0f, 0.2f,
					0.0f, 0.0f, 0.2f,

					1.0f, 1.0f, 1.0f,

					0.35f, 0.25f, 0.0f,
					0.35f, 0.25f, 0.0f,
					0.35f, 0.25f, 0.0f,
					0.35f, 0.25f, 0.0f,

					0.35f, 0.25f, 0.0f,
					0.35f, 0.25f, 0.0f,
					0.35f, 0.25f, 0.0f
};


static GLfloat vert[] = {
				0,0,        ///trava
				0,500,
				700,500,
				700,0,

				0,250,      ///nebo
				0,500,
				700,500,
				700,250,

				250,250,    ///sun/moon

				175,125,    ///dom
				175,215,
				255,215,
				255,125,

				125,215,    ///krisha
				295,215,
				215,255

};




void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, vert);
	glColorPointer(3, GL_FLOAT, 0, (rise > 0)?colorA:colorB);
	glDrawArrays(GL_QUADS, 0, 8);
	if (rise > 0) {
		glColor3f(1.0, 1.0, 0.0);
	}
	else {
		glColor3f(1.0, 1.0, 1.0);
		drawSun((rise > 0)? 700 * rise / 100 : 700 * (rise + 100) / 100, 375, 50, 128);
		glDrawArrays(GL_QUADS, 9, 4);
		glDrawArrays(GL_TRIANGLES, 13, 3);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
	}
	glFlush();
}


void logic() {
	rise--;
	if (rise < -100)
		rise = 100;

	vert[16] = (rise > 0) ? 700 * rise / 100 : 700 * (rise + 100) / 100;
	vert[17] = 375;

	display();
}


void Reshape(int Width, int Height)
{
	if (Height == 0) {
		Height = 1;
	}
	glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)Width, 0.0, (GLdouble)Height);
	display();
}


void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(700, 500);
	glutCreateWindow("VertexHouse");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(logic);
	glutMainLoop();
	return 0;
}







