#include "context.h"

#include <GL/glew.h>

Context::Context()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.depthBits = 24;
    settings.stencilBits = 8;

    window.create({1280, 720}, "Cube_World", sf::Style::Close, settings);
    window.setFramerateLimit(60);

    glewInit();

    glewExperimental = GL_TRUE;
    glClearColor(0.6784f, 0.8f, 1.0f, 1.0f);
    glViewport(0, 0, 1280, 720);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);

    //window.setFramerateLimit(144);
}
