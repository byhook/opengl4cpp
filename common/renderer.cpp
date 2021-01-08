#include <iostream>
#include "renderer.h"


SurfaceRenderer::SurfaceRenderer(const char *vertexPath, const char *fragmentPath) {
    this->pShader = new Shader(vertexPath, fragmentPath);
    std::cout << "SurfaceRenderer SurfaceRenderer" << std::endl;
}

SurfaceRenderer::~SurfaceRenderer() {
    std::cout << "SurfaceRenderer ~SurfaceRenderer" << std::endl;
}

void SurfaceRenderer::onSurfaceCreated() {
    std::cout << "SurfaceRenderer onSurfaceCreated" << std::endl;
    if (NULL != pShader) {
        pShader->setupProgram();
    }
}

void SurfaceRenderer::onSurfaceChanged() {
    std::cout << "onSurfaceChanged" << std::endl;
}

void SurfaceRenderer::onDrawFrame() {;
    //清除背景
    glClear(GL_COLOR_BUFFER_BIT);
    //激活程序
    if (NULL != pShader) {
        pShader->useProgram();
    }
}

void SurfaceRenderer::onRelease() {
    std::cout << "SurfaceRenderer onRelease" << std::endl;
    if (NULL != pShader) {
        delete this->pShader;
        this->pShader = NULL;
    }
}
