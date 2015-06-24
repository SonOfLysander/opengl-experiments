#include "LUtil.h"

// The current color rendering mode
int gColorMode = COLOR_MODE_CYAN;
// The projection scale
GLfloat gProjectionScale = 1.f;

bool initGL()
{
	// Initialize Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);
	// Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	// Check for errors
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenFL %s\n", gluErrorString(error));
		return false;
	}
	return true;
}

void update()
{
	// Empty. We're only drawing a quad. There is no animation.
}

void render()
{
	// Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);
	// Render the quad
	glBegin(GL_QUADS);
	float halfLength = 0.5f;
	glVertex2f(-halfLength, -halfLength);
	glVertex2f(halfLength, -halfLength);
	glVertex2f(halfLength, halfLength);
	glVertex2f(-halfLength, halfLength);
	glEnd();
	// Update screen
	glutSwapBuffers();
}

void runMainLoop(int val)
{
	// Frame logic
	update();
	render();

	// Run frame one more time
	glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, val);
}
