#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <SFML/Graphics.hpp>
#include "camera.h"
#include "frameRate.h"

class WorldController;
class Database;

class Player {
    public:

        explicit Player(WorldController* controller, Database * database);
        ~Player();

        void handleInput(const sf::RenderWindow& window, float delta);

        void handleKeyboard(float deltaTime);
        void handleMouseMovement(const sf::RenderWindow& window);
        void handleMouseScroll(int step);   // scroll wheel step

        glm::mat4 GetCameraMatrix();

    private:
        WorldController* controller;

        Camera * m_pCamera;
        Database * m_pDatabase;
        /* Update with shader manager */
        std::vector<BasicShader*>  using_shader;

        bool jumping_ = false;
        bool flying_;
        glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 0.0f) ;
        glm::mat4 camera_matrix;

};

#endif
