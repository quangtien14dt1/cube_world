#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include"VBO.h"

class VAO {
    public:

        GLuint ID;

        VAO() {
            glGenVertexArrays(1, &ID);
        };
        // Links a VBO Attribute such as a position or color to the VAO
        void LinkAttrib(
            VBO& VBO,
            GLuint layout,
            GLuint numComponents,
            GLenum type,
            GLsizeiptr stride,
            void* offset
        )
        {
            // logger in
            VBO.Bind();
            glVertexAttribPointer(
                layout,         // match the layout in the shader
                numComponents,  // size
                type,           // type
                GL_FALSE,       // normalized?
                stride,         // stride
                offset          // array buffer offset
            );
            glEnableVertexAttribArray(layout);
            VBO.Unbind();
            // logger out
        };

        /*
            vao usage functions
        */
        void Bind(){
            glBindVertexArray(ID);
        };
        void Unbind(){
            glBindVertexArray(0);
        };
        void Delete(){
            glDeleteVertexArrays(1, &ID);
        };
};

#endif
