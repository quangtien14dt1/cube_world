#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "camera.h"
#include "frameRate.h"

class WorldController;
class Database;

class Player {
    public:

        explicit Player(WorldController* controller, Database * database);
        ~Player();

        void ProcessKeyboard(Camera_Movement direction, float deltaTime);
        void ProcessMouseMovement(float xoffset, float yoffset);
        void ProcessMouseScroll(float yoffset);

        glm::mat4 GetCameraMatrix();

    private:
        WorldController* controller;

        Camera * m_pCamera;
        Database * m_pDatabase;
        /* Update with shader manager */
        BasicShader* shader;

        bool jumping_ = false;
        bool flying_;
        glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 0.0f) ;
        glm::mat4 camera_matrix;

};

#endif
