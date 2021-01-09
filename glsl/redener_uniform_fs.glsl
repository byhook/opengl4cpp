#version 330 core
out vec4 FragColor;

//在OpenGL程序代码中设定这个变量
uniform vec4 ourColor;

void main()
{
    FragColor = ourColor;
}