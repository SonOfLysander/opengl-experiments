bool initGL()
{
	// Initialize Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
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
