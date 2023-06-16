#ifndef SHADER_UNTIL_CLASS_H
#define SHADER_UNTIL_CLASS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <fstream>
#include <helpers/RootDir.h>

std::string loadFile(const std::string& filename);

GLuint compileShader(const GLchar *source, GLenum shaderType);

GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID);

#endif
