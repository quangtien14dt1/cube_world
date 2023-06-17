#include "player.h"


Player::Player(WorldController* controller, Database * database )
    :   controller{controller} , m_pDatabase{database}
{}



glm::mat4 Player::GetCameraMatrix() {
    camera_matrix =  m_pCamera->getCameraMatrix();
    return camera_matrix;
}


void Player::handleInput(const sf::RenderWindow& window, float delta) {
    handleKeyboard(delta);
    handleMouseMovement(window);
}

void Player::handleKeyboard(float delta) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) m_pCamera->ProcessKeyboard(FORWARD, delta);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) m_pCamera->ProcessKeyboard(BACKWARD, delta);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) m_pCamera->ProcessKeyboard(LEFT, delta);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) m_pCamera->ProcessKeyboard(RIGHT, delta);

}

void Player::handleMouseMovement(const sf::RenderWindow& window) {
    static auto lastMousePosition = sf::Mouse::getPosition(window);// brilliant call this before call function
    auto change = sf::Mouse::getPosition() - lastMousePosition;

    m_pCamera->ProcessMouseMovement(change.x, change.y, true);

    // reset mouse position
    auto cx = static_cast<int>(window.getSize().x / 2);
    auto cy = static_cast<int>(window.getSize().y / 2);
    sf::Mouse::setPosition({cx, cy}, window);

    lastMousePosition = sf::Mouse::getPosition();

}

void Player::handleMouseScroll(int step) {
    m_pCamera->ProcessMouseScroll(step);
}
