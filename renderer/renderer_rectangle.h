
#ifndef OPENGL_RENDERER_1_RECTANGLE_H
#define OPENGL_RENDERER_1_RECTANGLE_H

#include "renderer.h"

class RendererRectangle : public SurfaceRenderer {

protected:

    void onSurfaceCreated();

    void onSurfaceChanged();

    void onDrawFrame();

    void onRelease();

private:

    unsigned int VAO, VBO, EBO;

public:

    RendererRectangle();

};


#endif //OPENGL_RENDERER_1_RECTANGLE_H
