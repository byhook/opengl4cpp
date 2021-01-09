
#include "shader.h"


Shader::Shader(const GLchar *vertexPath, const GLchar *fragmentPath) {
    this->vertexPath = vertexPath;
    this->fragmentPath = fragmentPath;
}

Shader::~Shader() {
    glDeleteProgram(programID);
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

bool Shader::checkCompileErrors(unsigned int id, bool isProgram) {
    int success;
    if (isProgram) {
        glGetProgramiv(id, GL_LINK_STATUS, &success);
    } else {
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    }
    return success;
}

bool Shader::setupProgram() {
    std::string vertexCode;
    loadShaderSource(vertexPath, vertexCode);
    std::string fragmentCode;
    loadShaderSource(fragmentPath, fragmentCode);

    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    if (!checkCompileErrors(vertex, false)) {
        std::cout << "compile vertex shader error" << std::endl;
        return false;
    }
    std::cout << "compile vertex shader success" << std::endl;
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    if (!checkCompileErrors(fragment, false)) {
        std::cout << "compile fragment shader error" << std::endl;
        return false;
    }
    std::cout << "compile fragment shader success" << std::endl;

    programID = glCreateProgram();
    glAttachShader(programID, vertex);
    glAttachShader(programID, fragment);
    glLinkProgram(programID);
    if (!checkCompileErrors(programID, true)) {
        std::cout << "compile program shader error" << std::endl;
        return false;
    }
    std::cout << "compile program shader success" << std::endl;
    //已经链接到程序里里,这里可以删除了
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return true;
}

void Shader::useProgram() {
    glUseProgram(programID);
}


unsigned int Shader::getProgramID() {
    return programID;
}