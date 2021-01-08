
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

    GLContext(OnSurfaceRenderer *pOnSurfaceRenderer);

    ~GLContext();

    int initGLContext();

};


#endif //OPENGL_CONTEXT_H
