
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

    /**
     * 读取本地的着色器资源
     * @param shaderPath
     * @param shaderCode
     */
    static void loadShaderSource(const char *shaderPath, std::string &shaderCode);

    /**
     * 检查程序/着色器是否编译成功
     * @param shader
     * @param isProgram
     * @return
     */
    static bool checkCompileErrors(unsigned int shader, bool isProgram);

public:

    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);

    ~Shader();

    bool setupProgram();

    void useProgram();

    unsigned int getProgramID();

};


#endif //OPENGL_SHADER_PROGRAM_H
