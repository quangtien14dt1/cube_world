/**
 * Copyright (C) 2023 QuangTien
 **/
#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include "../untils/math.h"
#include "shader_utils.h"


/*
    Basic shader using all object include cube
*/
class BasicShader {

    public:
        GLuint m_shaderProgram;
        const std::string shaderName;

        BasicShader(
            const std::string & vertexPath,
            const std::string & fragPath,
            std::string & name
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
