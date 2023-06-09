#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stb_image.h>
#include <vector>
#include "models/type.h"
#include "shaders/basicShader.h"
#include "textures/basicTexture.h"
#include "models/mesh.h"


class Shader;
class Mesh;
class Camera;
class Texture;

class Application {

    public:

        Application();

        ~Application();

        void Run();

        void InitWindow();

    private:

        GLFWwindow *window_;//must be the first

        int width_, height_;
};

#endif
