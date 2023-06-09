#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera {
    public:
        // camera Attributes
        glm::vec3 Position;

        glm::vec3 Front;        // z
        glm::vec3 Up;           // y
        glm::vec3 Right;        // x
        glm::vec3 WorldUp;
        /*
            euler Angles
        */
        float Yaw;
        float Pitch;
        float Roll;

        // camera options
        float MovementSpeed;
        float MouseSensitivity;
        float Zoom;

        /*
            contructors with vectors / scalar
        */
        Camera( glm::vec3 position ,
                glm::vec3 up,
                float yaw ,
                float pitch
        );

        Camera(
            float posX,
            float posY,
            float posZ,
            float upX,
            float upY,
            float upZ,
            float yaw,
            float pitch
        );

        // returns the view matrix calculated using Euler Angles and the LookAt Matrix
        glm::mat4 GetViewMatrix();

        /*
            usage function handle input
        */
        void ProcessKeyboard(Camera_Movement direction, float deltaTime);
        void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch);
        void ProcessMouseScroll(float yoffset);

    private:
        // calculates the front vector from the Camera's (updated) Euler Angles
        void updateCameraVectors();
};
#endif
