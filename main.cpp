#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "common/shader.h"
#include "common/context.h"
#include "common/renderer.h"

int main() {
    GLContext glContext;
    Shader triangleShader("../glsl/chapter_1_vs.glsl", "../glsl/chapter_1_fs.glsl");
    SurfaceRenderer surfaceRenderer(&triangleShader);
    glContext.setSurfaceRenderer(&surfaceRenderer);
    glContext.initGLContext();
    return 0;
}