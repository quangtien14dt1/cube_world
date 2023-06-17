#include <helpers/RootDir.h>
#include "application.h"
#include "untils/fileSystem.h"


// Vertex vertices[] = {
//     // Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
//     // positions                           // normals
//     // Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)},
//     // Vertex{glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)},
//     // Vertex{glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)},
//     // Vertex{glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)},
//     // Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
//     // Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)},

//     // Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)},
//     // Vertex{glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},
//     // Vertex{glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 1.0f)},
//     // Vertex{glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 1.0f)},
//     // Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 1.0f)},
//     // Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)},

//     // Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},
//     // Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)},
//     // Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
//     // Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
//     // Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)},
//     // Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},

//     // Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},
//     // Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)},
//     // Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
//     // Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
//     // Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)},
//     // Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},

//     // Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
//     // Vertex{glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)},
//     // Vertex{glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},
//     // Vertex{glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},
//     // Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)},
//     // Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},

//     // Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
//     // Vertex{glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)},
//     // Vertex{glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},
//     // Vertex{glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)},
//     // Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 0.0f)},
//     // Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f)},
// };

Application::~Application() {
    if(m_pWorldController != nullptr) {
        delete m_pWorldController;
    }
}
void Application::InitWindow()
{
    /* Create World controller */
    m_pWorldController = new WorldController(this);

}

void Application::runLoop()
{
    InitWindow();

    sf::Event e;

    sf::Clock dtTimer;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    dtTimer.restart();
    while (m_context.window.isOpen())
    {
        auto deltaTime = dtTimer.restart();

        handleEvents();

        m_pWorldController->handleInput(deltaTime.asSeconds());
        m_pWorldController->Update(deltaTime.asSeconds());

    }
}

void Application::handleEvents()
{
    sf::Event e;
    while (m_context.window.pollEvent(e))
    {
        switch(e.type)
        {
            case sf::Event::Closed:
                m_context.window.close();
                break;

            case sf::Event::KeyPressed:
                switch(e.key.code)
                {
                    case sf::Keyboard::Escape:
                        m_context.window.close();
                        break;

                    default:
                        break;
                }
                break;

            case sf::Event::MouseWheelScrolled:
                m_pWorldController->handleScrollWheel(e.mouseWheel.delta);

            default:
                break;
        }
    }
}



// void Application::loadContent() {


//     /* Creat textures  */
//     Texture textures[] = {
//         Texture("container2.png", "diffuse"),
//     };

//     /* Create new Mesh */
//     std::vector <Vertex> verts {vertices, vertices + sizeof(vertices) / sizeof(Vertex)};
// 	std::vector <Texture> tex {textures, textures + sizeof(textures) / sizeof(Texture)};
//     Mesh Cube(verts, tex);

//     /* Create and apply basic shader */
//     BasicShader shaderProgram("basic.vert", "basic.frag");
//     shaderProgram.Activate();

//     glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//     glm::mat4 view          = glm::mat4(1.0f);
//     glm::mat4 projection    = glm::mat4(1.0f);
//     model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
//     view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//     projection = glm::perspective(
//                             glm::radians(45.0f),
//                             (float)width_ / (float)height_, 0.1f, 100.0f);

//     shaderProgram.loadMatrix4(shaderProgram.getUniformLocation("model"), model);
//     shaderProgram.loadMatrix4(shaderProgram.getUniformLocation("view"), view);
//     shaderProgram.loadMatrix4(shaderProgram.getUniformLocation("projection"), projection);

//     /* Draw mes object */
//     Cube.Draw(shaderProgram);
// }
