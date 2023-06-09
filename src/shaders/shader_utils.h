#ifndef SHADER_UNTIL_H_INCLUDED
#define SHADER_UNTIL_H_INCLUDED

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <helpers/RootDir.h>

std::string loadFile(const std::string& filename);

GLuint compileShader(const GLchar *source, GLenum shaderType);

GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID);

#endif
