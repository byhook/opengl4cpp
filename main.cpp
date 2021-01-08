#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "common/shader.h"
#include "common/context.h"
#include "common/renderer.h"
#include "renderer_triangle.h"
#include "renderer_rectangle.h"

int main() {
    SurfaceRenderer *pSurfaceRenderer = new RendererRectangle();

    GLContext glContext(pSurfaceRenderer);
    glContext.initGLContext();

    delete pSurfaceRenderer;
    return 0;
}