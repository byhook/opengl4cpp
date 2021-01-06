
#ifndef OPENGL_SHADER_PROGRAM_H
#define OPENGL_SHADER_PROGRAM_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {


private:

    unsigned int programID = -1;

    const GLchar *vertexPath;
    const GLchar *fragmentPath;

    void loadShaderSource(const char *shaderPath, std::string &shaderCode);

public:

    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);

    bool setupProgram();

    void useProgram();

};


#endif //OPENGL_SHADER_PROGRAM_H
