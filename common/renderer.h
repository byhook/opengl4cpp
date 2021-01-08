
#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "context.h"
#include "shader.h"

class SurfaceRenderer : public OnSurfaceRenderer {


protected:

    void onSurfaceCreated();

    void onSurfaceChanged();

    void onDrawFrame();

    void onRelease();

protected:

    Shader *pShader;

public:

    SurfaceRenderer(const char *vertexPath, const char *fragmentPath);

    ~SurfaceRenderer();

};


#endif //OPENGL_RENDERER_H
