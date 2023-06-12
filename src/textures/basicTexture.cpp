#include "basicTexture.h"
#include <stb_image.h>
#include <iostream>
#include <string>

Texture::Texture(const std::string& path, char* image_type)
{
    data = nullptr;
    type = image_type;
    glGenTextures(1, &m_idTexture);


    std::string file_name = ROOT_DIR "resources/textures/" + path;
    data = stbi_load(file_name.c_str(),
                        &width,
                        &height,
                        &numberColor,
                        4  );
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

char* Texture::getType() {
    return type;
}

Texture::~Texture() {
    glDeleteTextures(1, &m_idTexture);
}

void Texture::bindTexture() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_idTexture);
}

/*
    functions usage
*/
void Texture::setupTexture(const GLuint type) {
        glBindTexture(GL_TEXTURE_2D, m_idTexture);
        glTexStorage2D(
                        GL_TEXTURE_2D,
                        2 /* mip map levels */,
                        GL_RGB8,
                        width,
                        height
        );
        glTexSubImage2D(
                        GL_TEXTURE_2D,
                        0 /* mip map level */,
                        0 /* xoffset */,
                        0 /* yoffset */,
                        width,
                        height,
                        GL_RGBA,
                        GL_UNSIGNED_BYTE,
                        data
        );
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
    shader.Activate();
	GLuint location  = shader.getUniformLocation(uniform);

    // now passing acctualy texture in GPU
	glUniform1i(location, unit);
}
