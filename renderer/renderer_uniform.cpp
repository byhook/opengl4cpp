#include <cmath>
#include "renderer_uniform.h"
#include "GLFW/glfw3.h"

RendererUniform::RendererUniform() : SurfaceRenderer::SurfaceRenderer("../glsl/redener_uniform_vs.glsl",
                                                                        "../glsl/redener_uniform_fs.glsl") {
    std::cout << "RendererUniform RendererUniform" << std::endl;
}

void RendererUniform::onSurfaceCreated() {
    SurfaceRenderer::onSurfaceCreated();
    std::cout << "RendererUniform onSurfaceCreated" << std::endl;

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //复制顶点数组到缓冲区中供OpenGL使用
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    //顶点属性默认是禁用的，这里开启
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void RendererUniform::onSurfaceChanged() {
    SurfaceRenderer::onSurfaceChanged();
    std::cout << "RendererUniform onSurfaceChanged" << std::endl;
}

void RendererUniform::onDrawFrame() {
    SurfaceRenderer::onDrawFrame();

    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    int vertexColorLocation = glGetUniformLocation(pShader->getProgramID(), "ourColor");
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RendererUniform::onRelease() {
    SurfaceRenderer::onRelease();
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    std::cout << "RendererUniform onRelease" << std::endl;
}