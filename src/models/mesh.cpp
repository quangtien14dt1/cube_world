#include "mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<Texture>& textures)
{
    this->vertices = vertices;
    this->textures = textures;
    setupMesh();
}

void Mesh::setupMesh() {
    m_vao.Bind();
    // create buffer size data
    VBO m_vbo(vertices);

    m_vao.LinkAttrib(m_vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	m_vao.LinkAttrib(m_vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// m_vao.LinkAttrib(m_vbo, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
    // [ 0 1 2][3 4 5][6 7]
    // ---3---|--3---|--2--|

    m_vao.Unbind();
}

void Mesh::Draw(BasicShader &shader) {
    shader.Activate();
    m_vao.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
