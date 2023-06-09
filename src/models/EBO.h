#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <GL/glew.h>
#include <vector>
#include "mesh.h"

class EBO {
    public:
        GLuint m_mEleBuf;
        // Constructor that generates a Elements Buffer Object and links it to indices
        EBO(std::vector<GLuint>& meshData){
            glGenBuffers(1, &m_mEleBuf);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_mEleBuf);
            glBufferData(
                GL_ELEMENT_ARRAY_BUFFER,
                meshData.size(),
                meshData.data(),
                GL_STATIC_DRAW);

        };

        /*
            usage functions elements
        */
        void Bind() {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_mEleBuf);
        };
        void Unbind() {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        };
        void Delete(){
            glDeleteBuffers(1, &m_mEleBuf);
        };
};

#endif
