
#include "shader.h"


Shader::Shader(const GLchar *vertexPath, const GLchar *fragmentPath) {
    std::cout << "vertexPath " << vertexPath << std::endl;
    std::cout << "fragmentPath " << fragmentPath << std::endl;
    this->vertexPath = vertexPath;
    this->fragmentPath = fragmentPath;
}

void Shader::loadShaderSource(const char *shaderPath, std::string &shaderCode) {
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        shaderFile.open(shaderPath);
        std::stringstream shaderStream;
        //读取文件的内容
        shaderStream << shaderFile.rdbuf();
        //关闭文件处理器
        shaderFile.close();
        shaderCode = shaderStream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "error load shader file " << std::endl;
    }
}

bool Shader::setupProgram() {
    std::string vertexCode;
    loadShaderSource(vertexPath, vertexCode);
    std::string fragmentCode;
    loadShaderSource(fragmentPath, fragmentCode);

    const char * vShaderCode = vertexCode.c_str();
    const char * fShaderCode = fragmentCode.c_str();

    unsigned int vertex,fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1,&vShaderCode,NULL);
    glCompileShader(vertex);


    std::cout << "vShaderCode:\r\n" << vShaderCode << std::endl;

    return false;
}

void Shader::useProgram() {

}