
#include "renderer_rectangle.h"

RendererRectangle::RendererRectangle() : SurfaceRenderer::SurfaceRenderer("../glsl/redener_ebo_vs.glsl",
                                                                        "../glsl/redener_ebo_fs.glsl") {
    std::cout << "RendererRectangle RendererRectangle" << std::endl;
}

void RendererRectangle::onSurfaceCreated() {
    SurfaceRenderer::onSurfaceCreated();
    std::cout << "RendererRectangle onSurfaceCreated" << std::endl;

    float vertices[] = {
            0.5f, 0.5f, 0.0f, //右上角
            0.5f, -0.5f, 0.0f, //右下角
            -0.5f, -0.5f, 0.0f,  //左下角
            -0.5f, 0.5f, 0.0f //左上角
    };

    //索引从0开始
    unsigned int indices[] = {
            0, 1, 2,  //第一个三角形
            0, 2, 3   //第二个三角形
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //复制顶点数组到缓冲区中供OpenGL使用
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    //顶点属性默认是禁用的，这里开启
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void RendererRectangle::onSurfaceChanged() {
    SurfaceRenderer::onSurfaceChanged();
    std::cout << "RendererRectangle onSurfaceChanged" << std::endl;
}

void RendererRectangle::onDrawFrame() {
    SurfaceRenderer::onDrawFrame();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RendererRectangle::onRelease() {
    SurfaceRenderer::onRelease();
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    std::cout << "RendererRectangle onRelease" << std::endl;
}