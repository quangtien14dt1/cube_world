
#include "camera.h"

/*
    constructors which thatc config camera atttributes and auler angler
    first one using vector
    second one using scalar (scale number)
*/
Camera::Camera(glm::vec3& position) {
    // position on world coordinate
    eye                 = position;
    target              = glm::vec3(0.0f, 0.0f, -1.0f);

    MovementSpeed       = SPEED;
    MouseSensitivity    = SENSITIVITY;
    Zoom                = ZOOM;

    Yaw                 = YAW;
    Pitch               = PITCH;

    updateCameraVectors();
}

/*
    positions on world corrdinates
    directtion
    euler angles
*/
Camera::Camera(float posX, float posY, float posZ) {
    eye                 = glm::vec3(posX, posY, posZ);
    target              = glm::vec3(0.0f, 0.0f, -1.0f);

    MovementSpeed       = SPEED;
    MouseSensitivity    = SENSITIVITY;
    Zoom                = ZOOM;

    Yaw                 = YAW;
    Pitch               = PITCH;

    updateCameraVectors();
}

void Camera::setPerspective(int width, int height, float near, float far){
    float aspect = float(width)/float(height);
    perspectiveMatrix = glm::perspective(glm::radians(Zoom), aspect, near, far);

    /* Set cursor position at center of monitor */
    SetMousePosition(width / 2, height / 2);
}

glm::mat4 Camera::GetViewMatrix() {
    return glm::lookAt( eye, eye + target, upDirection);
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime){
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)   eye += upDirection * velocity;
    if (direction == BACKWARD)  eye -= upDirection * velocity;
    if (direction == LEFT)      eye -= upDirection * velocity;
    if (direction == RIGHT)     eye += upDirection * velocity;
}

void Camera::ProcessMouseMovement(float x, float y, GLboolean constrainPitch = true){

    // updateing yaw
	Yaw += (x - mousePosition.x) * MouseSensitivity;
	if(Yaw > twoPI) Yaw -= twoPI;
	else if(Yaw < -twoPI) Yaw += twoPI;

	// updateing pitch
	Pitch += (y - mousePosition.y) * MouseSensitivity;
	if(Pitch > twoPI) Pitch -= twoPI;
	else if(Pitch < -twoPI) Pitch += twoPI;

    SetMousePosition(x, y);

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::SetMousePosition(float x, float y){
	mousePosition.x = x;
	mousePosition.y = y;
}

void Camera::ProcessMouseScroll(float yoffset){
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)    Zoom = 1.0f;
    if (Zoom > 45.0f)   Zoom = 45.0f;
}

void Camera::updateCameraVectors() {
    // calculate the new target vector
    glm::vec3 new_target;
    new_target.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    new_target.y = sin(glm::radians(Pitch));
    new_target.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    target = glm::normalize(new_target);

    // also re-calculate the Right and upDir vector
    rightHand = glm::normalize(glm::cross(target, glm::vec3(0.0f, 1.0f, 0.0f)));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    upDirection = glm::normalize(glm::cross(rightHand, target));
}

glm::mat4 Camera::getCameraMatrix() {
    return GetViewMatrix() * perspectiveMatrix;
}
