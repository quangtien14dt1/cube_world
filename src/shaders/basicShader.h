/**
 * Copyright (C) 2023 QuangTien
 **/
#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <string>
#include <fstream>
#include <json.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace  shaderUntil{
    std::string loadFile(const std::string& filename) {
        if (filename.empty()) {
            return "";
        }

        std::string filetext;
        std::string line;

        // create file content that read from

        std::ifstream inFile("/home/yamaha/Downloads/Finally/res/shaders/" + filename);

        // checking if create success
        if (!inFile) {
            fprintf(stderr, "COULD NOT OPEN FILE : %s \n", filename.c_str());
            inFile.close();
            return "";
        }
        else {
            while (getline(inFile, line)) {
                filetext.append(line + "\n");
            }
            inFile.close();
            return filetext;
        }
    }


    GLuint compileShader(const GLchar *source, GLenum shaderType) {
        /*
            if this create Segment Fault then checking for glfwInit()
            it have to init before create shader
            */
        GLuint shaderID = glCreateShader(shaderType);

        glShaderSource(shaderID, 1, &source, nullptr);
        glCompileShader(shaderID);

        GLint isSuccess = 0;
        GLchar infoLog[512];

        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isSuccess);
        if (!isSuccess) {
            glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
            throw std::runtime_error("UNABLE TO LOAD SHADER : " +
                                    std::string(infoLog));
        }

        return shaderID;
    }

    // link shader and fragment and return an program id
    GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID) {
        GLuint id = glCreateProgram();
        glAttachShader(id, vertexShaderID);
        glAttachShader(id, fragmentShaderID);

        glLinkProgram(id);

        /* delete vertext , fragment */
        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
        return id;
    }
}


/*
    Basic shader using all object include cube
*/
class BasicShader {

    public:
        GLuint m_shaderProgram;

        BasicShader(
                const std::string & vertexPath,
                const std::string & fragmentPath
        );

        virtual ~BasicShader() {} ;

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

    private:


        /* get location on buffer data that need to modifile */
        bool getUniformLocation(const std::string & uniform_name);
};



#endif
