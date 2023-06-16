#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include "VAO.h"
#include "EBO.h"
#include "type.h"
/*
    include for drawing using shader and camera
*/
#include "../shaders/basicShader.h"
#include "../player/camera.h"
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
