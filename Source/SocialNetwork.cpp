#include "SocialNetwork.h"

SocialNetwork::SocialNetwork()
{
	screenWidth = 800.0f;
	screenHeight = 800.0f;
	aspect = 1.0f;
	camX = 0.0f;
	camY = 0.0f;
	speed = 0.01f;
	zoom = 2.6667f;
	mouseX = 0.0;
	mouseY = 0.0;
	network = new Network();
	window = nullptr;
	proj = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	runConsole = false;
}
void SocialNetwork::run()
{
	window = initGraphics();
	if (window == NULL) return;

	std::string userFile = "../Resources/Saves/users.txt";
	Console console(network, userFile);
	Exit* exitButton = new Exit();
	exitButton->init();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.13f, 0.13f, 0.13f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		getCameraInputs(window);

		if (runConsole) console.run();
		runConsole = false;

		proj = glm::ortho(-aspect * zoom, aspect * zoom, -1.0f * zoom, 1.0f * zoom);
		view = glm::translate(glm::mat4(1.0f), glm::vec3(-camX, -camY, 0.0f));
		network->render(proj, view);
		exitButton->render(aspect);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}

void SocialNetwork::getCameraInputs(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) camY += speed;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) camY -= speed;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) camX -= speed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) camX += speed;
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) zoom -= 0.01f;
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) zoom += 0.01f;
	if (camX < -2.0f) camX = -2.0f;
	if (camX > 2.0f) camX = 2.0f;
	if (camY < -2.0f) camY = -2.0f;
	if (camY > 2.0f) camY = 2.0f;
	if (zoom < 0.1f) zoom = 0.1f;
	if (zoom > 5.0f) zoom = 5.0f;
}
glm::vec2 SocialNetwork::screenToWorld2D()
{
	float x = (2.0f * (float)mouseX) / screenWidth - 1.0f;
	float y = 1.0f - (2.0f * (float)mouseY) / screenHeight;
	glm::vec4 world = glm::inverse(proj * view) * glm::vec4(x, y, 0.0f, 1.0f);
	return glm::vec2(world.x, world.y);
}
glm::vec2 SocialNetwork::screenToNDC()
{
	float x = (2.0f * (float)mouseX) / screenWidth - 1.0f;
	float y = 1.0f - (2.0f * (float)mouseY) / screenHeight;
	return glm::vec2(x, y);
}
void SocialNetwork::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	SocialNetwork* self = (SocialNetwork*)glfwGetWindowUserPointer(window);
	if (!self) return;

	glViewport(0, 0, width, height);
	self->screenWidth = (float)width;
	self->screenHeight = (float)height;
	self->aspect = self->screenWidth / self->screenHeight;
}
void SocialNetwork::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button != GLFW_MOUSE_BUTTON_LEFT || action != GLFW_PRESS) return;
	SocialNetwork* self = (SocialNetwork*)glfwGetWindowUserPointer(window);
	if (!self) return;

	glfwGetCursorPos(window, &self->mouseX, &self->mouseY);

	if (self->network->tryExit(self->screenToNDC(), self->aspect)) self->runConsole = true;
	else self->network->trySelectUser(self->screenToWorld2D());
}
GLFWwindow* SocialNetwork::initGraphics()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "Social Network - John Lee", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowUserPointer(window, this);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSwapInterval(1);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
	glewInit();
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_MULTISAMPLE);
	int fbWidth;
	int fbHeight;
	glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
	framebufferSizeCallback(window, fbWidth, fbHeight);
	return window;
}
