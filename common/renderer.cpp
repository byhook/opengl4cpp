#include <iostream>
#include "renderer.h"


SurfaceRenderer::SurfaceRenderer(Shader *pShader) {
    this->pShader = pShader;
}

SurfaceRenderer::~SurfaceRenderer() {
    this->pShader = NULL;
}

void SurfaceRenderer::onSurfaceCreated() {
    std::cout << "onSurfaceCreated" << std::endl;
    if (NULL != pShader) {
        pShader->setupProgram();
    }
}

void SurfaceRenderer::onSurfaceChanged() {
    std::cout << "onSurfaceChanged" << std::endl;
}

void SurfaceRenderer::onDrawFrame() {
    std::cout << "onDrawFrame" << std::endl;
    //清除背景
    glClear(GL_COLOR_BUFFER_BIT);
    //激活程序
    if (NULL != pShader) {
        pShader->useProgram();
    }
}

void SurfaceRenderer::onRelease() {
    std::cout << "onRelease" << std::endl;
}