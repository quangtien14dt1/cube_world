#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <GL/glew.h>
#include <memory>
#include <iostream>
#include <stb_image.h>
#include <vector>

#include "worldController.h"
#include "context.h"

class Application {

    public:
        /* Usage function */
        void InitWindow();

        /* Starting point processing */
        void runLoop();
        void handleEvents();
        const sf::RenderWindow& getWindow() const { return m_context.window; }

        ~Application();

    private:

        GLFWwindow *window_;//must be the first
        Context m_context;

        WorldController* m_pWorldController;

};

#endif
