#include "player.h"

Player::Player(WorldController* controller) {
    controller = controller;
    m_pCamera = new Camera(position_);

}

void Player::ProcessKeyboard(Camera_Movement direction, float deltaTime) {
    m_pCamera->ProcessKeyboard(direction, deltaTime);
}

void Player::ProcessMouseMovement(float xoffset, float yoffset){
    m_pCamera->ProcessMouseMovement(xoffset, yoffset, true);
}

void Player::ProcessMouseScroll(float yoffset) {

}

glm::mat4 Player::GetCameraMatrix() {
    camera_matrix =  m_pCamera->getCameraMatrix();
    return camera_matrix;
}
