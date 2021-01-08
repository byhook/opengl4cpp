#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "common/shader.h"
#include "common/context.h"
#include "common/renderer.h"
#include "renderer_1_triangle.h"

int main() {
    SurfaceRenderer *pSurfaceRenderer = new RendererTriangle("../glsl/redener_triangle_vs.glsl",
                                                            "../glsl/redener_triangle_fs.glsl");
    GLContext glContext;
    glContext.setSurfaceRenderer(pSurfaceRenderer);
    glContext.initGLContext();

    delete pSurfaceRenderer;
    return 0;
}