#include "basicTexture.h"
#include <stb_image.h>
#include <iostream>
#include <string>

Texture::Texture(const std::string& path, std::string& image_type)
{
    data = nullptr;
    type = image_type.data();
    glGenTextures(1, &m_idTexture);

    data = stbi_load(path.c_str(), &width, &height, &numberColor, 0);
    if(data) {
        switch (numberColor)
        {
            case 1:
                setupTexture(GL_RED);
                break;
            case 3:
                setupTexture(GL_RGB);
                break;
            case 4:
                setupTexture(GL_RGBA);
                break;
            default:
                break;
        }

    } else {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    // unbind texture avoid of accident access modifiled data
    unbindTexture();
}

unsigned int Texture::getTextureId() {
    return m_idTexture;
}

const char* Texture::getType() {
    return type;
}

Texture::~Texture() {
    glDeleteTextures(1, &m_idTexture);
}

/*
    functions usage
*/
void Texture::setupTexture(const GLuint type) {
        glBindTexture(GL_TEXTURE_2D, m_idTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        /*
            setting for image parameter
        */
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
}

void Texture::unbindTexture() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::deleteTexture() {
    glDeleteTextures(1, &m_idTexture);
}

void Texture::textureUnit ( BasicShader& shader,
                                 const char* uniform,
                                 GLuint unit )
{
	GLuint texUni = glGetUniformLocation(shader.m_shaderProgram, uniform);
	shader.Activate();
    // now passing acctualy texture in GPU
	glUniform1i(texUni, unit);
}