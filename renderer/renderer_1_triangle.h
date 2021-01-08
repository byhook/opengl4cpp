
#ifndef OPENGL_RENDERER_1_TRIANGLE_H
#define OPENGL_RENDERER_1_TRIANGLE_H

#include "renderer.h"

class RendererTriangle : public SurfaceRenderer {

protected:

    void onSurfaceCreated();

    void onSurfaceChanged();

    void onDrawFrame();

    void onRelease();

public:
    //声明继承基类的构造函数
    using SurfaceRenderer::SurfaceRenderer;

};


#endif //OPENGL_RENDERER_1_TRIANGLE_H
