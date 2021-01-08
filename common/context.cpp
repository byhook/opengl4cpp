#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "context.h"


GLContext::GLContext() {
    this->pOnSurfaceRenderer = NULL;
}

GLContext::~GLContext() {
    this->pOnSurfaceRenderer = NULL;
}

int GLContext::initGLContext() {
    //初始化配置
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    //创建一个窗口对象
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    //初始化GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        return -1;
    }

    if (NULL != this->pOnSurfaceRenderer) {
        this->pOnSurfaceRenderer->onSurfaceCreated();
    }

    //渲染循环-检查是否被要求退出
    while (!glfwWindowShouldClose(window)) {

        if (NULL != this->pOnSurfaceRenderer) {
            this->pOnSurfaceRenderer->onDrawFrame();
        }

        //交换颜色缓冲
        glfwSwapBuffers(window);
        //事件处理
        glfwPollEvents();
    }
    if (NULL != this->pOnSurfaceRenderer) {
        this->pOnSurfaceRenderer->onRelease();
    }
    //染循环结束完成释放
    glfwTerminate();
    return 0;
}

void GLContext::setSurfaceRenderer(OnSurfaceRenderer *pOnSurfaceRenderer) {
    this->pOnSurfaceRenderer = pOnSurfaceRenderer;
}