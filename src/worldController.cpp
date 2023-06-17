#include "worldController.h"
#include "application.h"


WorldController::WorldController(Application* app)
    :   m_pApplication{app}
{}

WorldController::~WorldController() {

}

void WorldController::Update(float deltaTime) {
    deltaTime = deltaTime;
}

void WorldController::handleInput(float delta) {
    m_pPlayer->handleInput(m_pApplication->getWindow(), delta);
}

void WorldController::handleScrollWheel(int steps) {
    m_pPlayer->handleMouseScroll(steps);
}

void WorldController::addNewShader(char* vertexPath,char* fragPath , std::string name)
{
    BasicShader newShader(vertexPath, fragPath, name);
    using_shaders.push_back(newShader);
}

void WorldController::addNewTexture(const std::string& file, char* type, std::string name)
{
    Texture newTexture(file, type, name);
    using_textures.push_back(newTexture);
}
