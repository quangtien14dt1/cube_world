#include "mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<Texture>& textures)
{
    this->vertices = vertices;
    this->textures = textures;
    setupMesh();
}

void Mesh::setupMesh() {

    /* Start using shader m_vao  */
    m_vao.Bind();

    /* Create buffer size and write on data */
    VBO m_vbo(vertices);

    /* Link VBO with m_vao*/
    m_vao.LinkAttrib(m_vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	m_vao.LinkAttrib(m_vbo, 1, 2, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	// m_vao.LinkAttrib(m_vbo, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));

    /* Stop using shader m_vao */
    m_vao.Unbind();
}

void Mesh::Draw(BasicShader &shader) {

    /* Using and activate shader */
    shader.Activate();

    /* Bind and activate texture */
    textures[0].textureUnit(shader, "tex_sampler" , 0);
    textures[0].bindTexture();

    m_vao.Bind();

    glDrawArrays(GL_TRIANGLES, 0, 36);

}
