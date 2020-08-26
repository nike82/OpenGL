#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//Constants
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    //GLFW Creating window

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, " OpenGL ", nullptr, nullptr);

    if (window == nullptr) {
        std::cout << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //GLAD: downloading all pointers to OpenGL functions

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialized GLAD" << std::endl;
        return -1;
    }

    //Rendering loop

    while (!glfwWindowShouldClose(window)) {
        //working on entered data
        processInput(window);

        //Rendering process
        glClearColor(0.2f, 0.3f, 0.3, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Swap front and back buffers. Working on events(press key,enter/out...)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //GLFW: finishing, released all the resources GLFW
    glfwTerminate();

    return 0;
}

//Working on entering events
void processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    }

//GLFW:everytime when window size changed, calls callback function
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
