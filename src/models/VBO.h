
#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <vector>
#include "type.h"

class VBO {
    public:
        GLuint m_mObjBuf;
        // Constructor that generates a Vertex Buffer Object and links it to vertices
        VBO(const std::vector<Vertex>& vertices){
            glGenBuffers(1, &m_mObjBuf);
            glBindBuffer(GL_ARRAY_BUFFER, m_mObjBuf);
            glBufferData(   GL_ARRAY_BUFFER,
                            vertices.size() * sizeof(Vertex),
                            vertices.data(),
                            GL_STATIC_DRAW     );
        };

        /*
            usage VBO functions
        */
        void Bind(){
            glBindBuffer(GL_ARRAY_BUFFER, m_mObjBuf);
        };
        void Unbind(){
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        };
        void Delete(){
            glDeleteBuffers(1, &m_mObjBuf);
        };
};

#endif
