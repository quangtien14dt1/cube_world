#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

#include <GL/glew.h>
#include <string>
#include "../math.h"


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

#endif
