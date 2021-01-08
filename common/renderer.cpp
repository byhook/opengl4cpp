#include <iostream>
#include "renderer.h"


SurfaceRenderer::SurfaceRenderer(const char *vertexPath, const char *fragmentPath) {
    this->pShader = new Shader(vertexPath, fragmentPath);
    std::cout << "SurfaceRenderer SurfaceRenderer" << std::endl;
}

SurfaceRenderer::~SurfaceRenderer() {
    if (NULL != pShader) {
        delete this->pShader;
        this->pShader = NULL;
    }
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

void SurfaceRenderer::onDrawFrame() {
    //std::cout << "onDrawFrame" << std::endl;
    //清除背景
    glClear(GL_COLOR_BUFFER_BIT);
    //激活程序
    if (NULL != pShader) {
        pShader->useProgram();
    }
}

void SurfaceRenderer::onRelease() {
    std::cout << "SurfaceRenderer onRelease" << std::endl;
}