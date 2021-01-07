
#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "surface.h"
#include "shader.h"

class SurfaceRenderer : public OnSurfaceRenderer {


private:

    void onSurfaceCreated();

    void onSurfaceChanged();

    void onDrawFrame();

    void onRelease();

private:

    Shader *pShader;

public:

    SurfaceRenderer(Shader *pShader);

    ~SurfaceRenderer();


};


#endif //OPENGL_RENDERER_H
