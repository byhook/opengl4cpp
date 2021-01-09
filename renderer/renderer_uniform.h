
#ifndef OPENGL_RENDERER_1_UNIFORM_H
#define OPENGL_RENDERER_1_UNIFORM_H

#include "renderer.h"

class RendererUniform : public SurfaceRenderer {

protected:

    void onSurfaceCreated();

    void onSurfaceChanged();

    void onDrawFrame();

    void onRelease();

private:

    unsigned int VAO, VBO;

public:

    RendererUniform();

};


#endif //OPENGL_RENDERER_1_UNIFORM_H
