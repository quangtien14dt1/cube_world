#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include <GL/glew.h>

#include "VAO.h"
#include "EBO.h"
#include "type.h"
/*
    include for drawing using shader and camera
*/
#include "../shaders/basicShader.h"
#include "../camera/camera.h"
#include "../textures/basicTexture.h"


class Mesh {
    public:
        std::vector<Vertex>         vertices;
        std::vector<Texture>        textures;

        Mesh( std::vector<Vertex>& vertices, std::vector<Texture>& textures );
        ~Mesh(){};

        void Draw(BasicShader &shader);

    private:
        VAO m_vao;  // generate vao id
        void setupMesh();
};

#endif
