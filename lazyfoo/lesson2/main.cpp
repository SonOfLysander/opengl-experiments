#include "LUtil.h"

void runMainLoop(int val);
/*
Pre Condition:
 -Initialized freeGLUT
Post Condition:
 -Calls the main loop functions and sets itself to be called back in 1000 / SCREEN_FPS milliseconds
Side Effects:
 -Sets glutTimerFunc
*/
int main(int argc, char* args[])
{
	// Initialize freeGLUT
	glutInit(&argc, args);
	// Create OpenGL 2.1 context
	glutInitContextVersion(2, 1);

	// Create double buffered window
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OpenGL");

	// Do post window/context creation initialization
	if (!initGL())
	{
		printf("Unable to initialize graphics library!\n");
		return 1;
	}

	// Set keyboard handler
	glutKeyboardFunc(handleKeys);

	// Set render function. #NOTE TO SELF: I think this is a C++ function pointer. I need to double check that, though.
	glutDisplayFunc(render);

	// Set main loop. #NOTE TO SELF: I think this, too, is a function pointer.
	glutTimerFunc(1000/ SCREEN_FPS, runMainLoop, 0);

	// Start GLUT main loop
	glutMainLoop();
	return 0;
}
