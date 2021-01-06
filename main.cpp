#include "common/shader.h"

int main() {
    Shader shader("../glsl/chapter_1_vx.glsl","");
    shader.setupProgram();
    return 0;
}