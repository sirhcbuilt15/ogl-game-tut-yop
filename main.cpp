/*
 * main.cpp
 *
 *  Created on: May 13, 2016
 *      Author: chris
 */

//#include <GLFW/glfw3.h>
//#include <stdlib.h>
//#include <stdio.h>
#include "GameWindow.h"

GameWindow *gameWindow;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "Open GL GAME_ME", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);

    gameWindow = new GameWindow(true, window);

    while (gameWindow->getRunning())
    {
	//glfwPollEvents();

	gameWindow->render();
	gameWindow->update();

	gameWindow->setRunning(!glfwWindowShouldClose(window));

	glfwPollEvents();
	//running = (!glfwWindowShouldClose(window));
    }

    delete gameWindow;

    glfwTerminate();
    exit(EXIT_SUCCESS);
}






