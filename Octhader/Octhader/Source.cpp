#include <GL\glut.h>
#include <GL\gl.h>
#include <GL\glu.h>
#include <stdio.h>


int size = 400;
bool light = true;

double rotate_y = 0;
double rotate_x = 0;
double position = 0;
double spherePosition = 0;

void display();
void specialKeys(int key, int x, int y);
void drawSphere();
void drawOctahedron();
void changeSpherePosition(int t);

void display() {

	if (light) {
		glutReshapeWindow(2 * size, 2 * size);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(spherePosition, 0.0, 1.0, 0.0);
	drawOctahedron();

	glColor3f(1, 1, 1);
	drawSphere();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay(); 


}

void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_RIGHT)
		spherePosition += 5;
	else if (key == GLUT_KEY_LEFT)
		spherePosition -= 5;
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;
	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
	else if (key == 'z')
		position += 0.005;
	else if (key == 'x')
		position -= 0.005;
	else if (key == 'q')
		exit(0);

	glutPostRedisplay();

}

void changeSpherePosition(int t) {
	glutTimerFunc(10, changeSpherePosition, 0);
	spherePosition += 0.5;
}

void drawOctahedron() {

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);


	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);     
	glVertex3f(0.25, -0.25 - position, -0.25 + position);
	glColor3f(0.0, 1.0, 0.0);    
	glVertex3f(-0.25, -0.25 - position, -0.25 + position);
	glColor3f(0.0, 0.0, 1.0);   
	glVertex3f(0.0, 0.25 - position, 0.0 + position);

	//аекши бепу рно
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.25, -0.25 - position, 0.25 - position);
	glVertex3f(-0.25, -0.25 - position, 0.25 - position);
	glVertex3f(0.0, 0.25 - position, 0.0 - position);

	//тхнкернбши рно
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.25 - position, -0.25 - position, -0.25);
	glVertex3f(0.25 - position, -0.25 - position, 0.25);
	glVertex3f(0.0 - position, 0.25 - position, 0.0);

	// гекемши рно яопюбю
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.25 + position, -0.25 - position, 0.25);
	glVertex3f(-0.25 + position, -0.25 - position, -0.25);
	glVertex3f(0.0 + position, 0.25 - position, 0.0);

	// фекрши
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.25, -0.25 + position, -0.25 + position);
	glVertex3f(-0.25, -0.25 + position, -0.25 + position);
	glVertex3f(0.0, -0.75 + position, -0.0 + position);

	// аекши
	glColor3f(1.0, 0.5, 0.5);
	glVertex3f(0.25, -0.25 + position, 0.25 - position);
	glVertex3f(-0.25, -0.25 + position, 0.25 - position);
	glVertex3f(0.0, -0.75 + position, 0.0 - position);

	// цнксани
	glColor3f(0.0, 0.5, 1.0);
	glVertex3f(0.25 - position, -0.25 + position, -0.25);
	glVertex3f(0.25 - position, -0.25 + position, 0.25);
	glVertex3f(0.0 - position, -0.75 + position, 0.0);

	// анкнрмши
	glColor3f(0.5, 0.5, 0.25);
	glVertex3f(-0.25 + position, -0.25 + position, 0.25);
	glVertex3f(-0.25 + position, -0.25 + position, -0.25);
	glVertex3f(0.0 + position, -0.75 + position, 0.0);
	glEnd();

}

void drawSphere() {

	/*
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat lights[] = {0.2, 0.2, 0.2, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, lights);
	GLfloat lightsPosition[] = {.5, .5, 0.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightsPosition);
	*/

	glTranslatef(0.5, 0.5, 0.5);
	glRotatef(spherePosition, 1.0, 0.0, 0.0);
	glRotatef(spherePosition, 0.0, 1.0, 1.0);
	glRotatef(spherePosition, 0.0, 1.0, 1.0);
	glutWireSphere(0.1, 36, 18);

}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(size / 2, size / 2);
	glutCreateWindow("Lab2");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutTimerFunc(10, changeSpherePosition, 0);
	glutMainLoop();
	return 0;

}


