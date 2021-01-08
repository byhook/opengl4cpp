
#include "renderer_triangle.h"

RendererTriangle::RendererTriangle() : SurfaceRenderer::SurfaceRenderer("../glsl/redener_vbo_vs.glsl",
                                                                        "../glsl/redener_vbo_fs.glsl") {
    std::cout << "RendererTriangle RendererTriangle" << std::endl;
}

void RendererTriangle::onSurfaceCreated() {
    SurfaceRenderer::onSurfaceCreated();
    std::cout << "RendererTriangle onSurfaceCreated" << std::endl;

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

void RendererTriangle::onSurfaceChanged() {
    SurfaceRenderer::onSurfaceChanged();
    std::cout << "RendererTriangle onSurfaceChanged" << std::endl;
}

void RendererTriangle::onDrawFrame() {
    SurfaceRenderer::onDrawFrame();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RendererTriangle::onRelease() {
    SurfaceRenderer::onRelease();
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    std::cout << "RendererTriangle onRelease" << std::endl;
}