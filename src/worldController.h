#ifndef WORLDCONTROLLER_CLASS_H
#define WORLDCONTROLLER_CLASS_H

#include "models/Database.h"
#include "player/player.h"

    // m_pPlayer = new Player(m_pWorldController,m_pDatabase);
    // m_pDatabase = new Database(m_pPlayer, m_pWorldController);

class WorldController {

    public:
        explicit WorldController(GLFWwindow *window);
        ~WorldController();

        void Resize(int width, int height);
        void Update(sf::Time& deltaTime);
        int width_, height_;
        bool control_;
    protected:
        /* hold state from parent  */
        GLFWwindow * m_pWindow;

        /* hold start of child instance */
        Player* m_pPlayer;
        Database*  m_pDatabase;
        Framerate* m_pFrameRate;

        static void FocusCallback(GLFWwindow *window, int focused);
        static void FramebufferSizeCallback(GLFWwindow *window, int width, int height);
        static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void ScrollCallback(GLFWwindow *window, double x_offset, double y_offset);

};


#endif
