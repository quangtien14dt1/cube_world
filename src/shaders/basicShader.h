/**
 * Copyright (C) 2023 QuangTien
 **/
#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <iostream>
#include <string>
#include <GL/glew.h>
#include "../math.h"
#include "shader_utils.h"


/*
    Basic shader using all object include cube
*/
class BasicShader {

    public:
        GLuint m_shaderProgram;

        BasicShader(
            const std::string & vertexPath,
            const std::string & fragPath
        );

        ~BasicShader();

        /* modifiled variable on program that load to CPU  */
        void loadInt(GLuint location, int value);
        void loadFloat(GLuint location, float value);
        void loadVector2(GLuint location, const glm::vec2 &vect);
        void loadVector3(GLuint location, const glm::vec3 &vect);
        void loadVector4(GLuint location, const glm::vec4 &vect);
        void loadMatrix4(GLuint location, const glm::mat4 &matrix);

        /* enable using shader program */
        void Activate();

        /* delete shader program */
        void Delete();

        /* get location on buffer data that need to modifile */
        GLuint getUniformLocation(const std::string & uniform_name);

    private:



};



#endif
