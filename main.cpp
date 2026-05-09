#include "cubix.h"

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow *window=glfwCreateWindow(800,800,"Rubik's Cube",nullptr,nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window,keyCallback);

    if (glewInit()!=GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW\n";
        glfwTerminate();
        return -1;
    }
    glEnable(GL_DEPTH_TEST);

    cube.randomize();

    while (!glfwWindowShouldClose(window))
    {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
