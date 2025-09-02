#pragma once

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include "Console.h"
#include "Exit.h"

class SocialNetwork
{
public:
	SocialNetwork();
	void run();
private:
	void getCameraInputs(GLFWwindow* window);
	glm::vec2 screenToWorld2D();
	glm::vec2 screenToNDC();
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	GLFWwindow* initGraphics();

	float screenWidth;
	float screenHeight;
	float aspect;
	float camX;
	float camY;
	float speed;
	float zoom;
	double mouseX;
	double mouseY;
	Network* network;
	GLFWwindow* window;
	glm::mat4 proj;
	glm::mat4 view;
	bool runConsole;
};