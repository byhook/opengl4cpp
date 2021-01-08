
#ifndef OPENGL_RENDERER_1_TRIANGLE_H
#define OPENGL_RENDERER_1_TRIANGLE_H

#include "renderer.h"

class RendererTriangle : public SurfaceRenderer {

protected:

    void onSurfaceCreated();

    void onSurfaceChanged();

    void onDrawFrame();

    void onRelease();

private:

    unsigned int VAO, VBO, EBO;

public:

    RendererTriangle();

};


#endif //OPENGL_RENDERER_1_TRIANGLE_H
