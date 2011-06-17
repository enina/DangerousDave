// 
//	The program draws an image and translate it according to 
//	keyboard pressing buttons. 'l' - left, 'r' - right, 'u' - up, 'd' - down. 
//
#include "davepch.h"
#include "Controler.h"

//---------------------
//========prototype========//
void init();
void idle();
void display();
void keyboard(unsigned char key, int x, int y);
//------------------

Controler game;
//-------------------
int main(int argc, char** argv)
{
	// Window initializing
	glutInit(&argc, argv);

	init ();

	glutIdleFunc(idle);
	glutDisplayFunc(display);  
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
//-----------------------------
// OpenGL initializing values
void init()
{
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA );//|GLUT_ALPHA);
	glutInitWindowSize (SCREEN_WIDTH,SCREEN_HEIGHT); 
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Dangerous Dave");
	glClearColor(0.0, 0.0, 0.0, 0);

	gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

}
//-------------------------
void idle() {
	game.idle();
}
//---------------
void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	glLoadIdentity();

	game.display();

	glFlush ();
	glutSwapBuffers();
}
//---------------------
void keyboard(unsigned char key, int x, int y) {
	game.keyboard(key,x,y);
}
//----------------------