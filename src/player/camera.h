#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../untils/math.h"
#include "../shaders/basicShader.h"

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const float YAW         = -90.0f;   // xoay theo truc y
const float PITCH       =  0.0f;    // xoay theo truc x
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;
const float ROLL        =  0.0f;    // xoay theo truc z


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera {
    public:
        // camera Attributes
        glm::vec3 eye;

        glm::vec3 target;
        glm::vec3 upDirection;
        glm::vec3 rightHand;

        glm::mat4 cameraMatrix = glm::mat4(1.0f);
        glm::mat4 perspectiveMatrix;
        glm::vec3 mousePosition;

        float twoPI = glm::two_pi<float>();
        float Yaw;      // xoay theo truc y
        float Pitch;    // xoay theo truc x
        // float Roll;      // xoay theo truc z

        // camera options
        float MovementSpeed;
        float MouseSensitivity;
        float Zoom;

        Camera( glm::vec3 & position);
        Camera(float posX,float posY,float posZ);

        void SetMousePosition(float x, float y);
        void ProcessKeyboard(Camera_Movement direction, float deltaTime);
        void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch);
        void ProcessMouseScroll(float yoffset);

        glm::mat4 GetViewMatrix();  // view matrix = lookAt
        void setPerspective(int width, int height, float near, float far);
        glm::mat4 getCameraMatrix();    // view * perspective matrix

    private:
        // calculates the front vector from the Camera's (updated) Euler Angles
        void updateCameraVectors();
};
#endif
