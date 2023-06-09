#ifndef CUBETEXTURE_H_INCLUDED
#define CUBETEXTURE_H_INCLUDED

#include <GL/glew.h>
#include <array>
#include <string>

class BasicTexture {
    public:
        BasicTexture    () = default;
        BasicTexture    (const std::array<std::string , 6> &files);
        ~BasicTexture   ();

        /*
            Load image by this order
            -right
            -left
            -top
            -bottom
            -back
            -front
        */
        void bindTexture        ();
        void unbindTexture      ();

    private:
        GLuint m_idTexture;
        GLenum m_format;
        int width, height , numberColor;
        unsigned char* data;
};


#endif
