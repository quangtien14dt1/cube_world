#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <GL/glew.h>
#include <string>
#include "../shaders/basicShader.h"

class Texture {
    public:
        Texture(const std::string& file,
                char* type);
        ~Texture();

        /*
            usage functions for textures
        */
        void setupTexture(const GLuint type);
        void unbindTexture();
        void deleteTexture();

        /*
            unifi function that passing image
        */
        void  textureUnit(BasicShader& shader, const char* uniform, GLuint unit);
        char* getType();
        unsigned int getTextureId();

    private:
        GLuint              m_idTexture;
        char*         type;
        int                 width, height , numberColor;
        unsigned char*      data;
};


#endif
