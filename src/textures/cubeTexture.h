#ifndef CUBETEXTURE_H_INCLUDED
#define CUBETEXTURE_H_INCLUDED

#include <GL/glew.h>
#include <array>
#include <string>
#include "basicTexture.h"

class CubeTextures  {
    public:
        CubeTextures    () = default;
        CubeTextures    (const std::array<std::string , 6> &files);
        ~CubeTextures   ();

        /*
            Load image by this order
            -right
            -left
            -top
            -bottom
            -back
            -front
        */
        void bindTexture();
        void unbindTexture();
        void deleteTexture();
        void setupTexture(const GLuint type);

        void  textureUnit(BasicShader& shader, const char* uniform, GLuint unit);
        char* getType();
        unsigned int getTextureId();

    private:
        GLuint m_idTexture;
        GLenum m_format;
        int width, height , numberColor;
        unsigned char* data;
};


#endif
