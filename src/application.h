#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GL/glew.h>
#include <memory>
#include <iostream>
#include <stb_image.h>
#include <vector>

#include "models/type.h"
#include "shaders/basicShader.h"
#include "textures/basicTexture.h"
#include "models/mesh.h"
#include "worldController.h"
#include "models/Database.h"
#include "context.h"

class Application {

    public:
        /* Usage function */
        void InitWindow();

        /* Starting point processing */
        void runLoop();
        void handleEvents();

        ~Application();

    private:

        GLFWwindow *window_;//must be the first
        Context m_context;

        WorldController* m_pWorldController;
        int     width_, height_;
        int     frameCount = 0;
        float   gameTime = 0.0f;
        Mesh* meshObject{nullptr};
};

#endif
