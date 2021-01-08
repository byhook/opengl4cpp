
#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H


class OnSurfaceRenderer {

public:

    virtual void onSurfaceCreated() = 0;

    virtual void onSurfaceChanged() = 0;

    virtual void onDrawFrame() = 0;

    virtual void onRelease() = 0;

};


class GLContext {

private:

    OnSurfaceRenderer *pOnSurfaceRenderer;

public:

    GLContext();

    ~GLContext();

    int initGLContext();

    void setSurfaceRenderer(OnSurfaceRenderer *pOnSurfaceRenderer);

};


#endif //OPENGL_CONTEXT_H
