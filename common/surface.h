
#ifndef OPENGL_SURFACE_H
#define OPENGL_SURFACE_H


class OnSurfaceRenderer {

public:

    virtual void onSurfaceCreated() = 0;

    virtual void onSurfaceChanged() = 0;

    virtual void onDrawFrame() = 0;

    virtual void onRelease() = 0;

};


class Surface {

private:

    OnSurfaceRenderer *pOnSurfaceRenderer;

public:

    Surface();

    ~Surface();

    int setupSurface();


    void setSurfaceRenderer(OnSurfaceRenderer *pOnSurfaceRenderer);

};


#endif //OPENGL_SURFACE_H
