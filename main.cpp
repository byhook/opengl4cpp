#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "common/shader.h"
#include "common/surface.h"
#include "common/renderer.h"

int main() {
    Surface surface;
    Shader triangleShader("../glsl/chapter_1_vs.glsl", "../glsl/chapter_1_fs.glsl");
    SurfaceRenderer surfaceRenderer(&triangleShader);
    surface.setSurfaceRenderer(&surfaceRenderer);
    surface.setupSurface();

    return 0;
}