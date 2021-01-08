
#include "renderer_1_triangle.h"


void RendererTriangle::onSurfaceCreated() {
    SurfaceRenderer::onSurfaceCreated();
    std::cout << "RendererTriangle onSurfaceCreated" << std::endl;
}

void RendererTriangle::onSurfaceChanged() {
    SurfaceRenderer::onSurfaceChanged();
    std::cout << "RendererTriangle onSurfaceChanged" << std::endl;
}

void RendererTriangle::onDrawFrame() {
    SurfaceRenderer::onDrawFrame();
}

void RendererTriangle::onRelease() {
    SurfaceRenderer::onRelease();
}