#ifndef WORLDCONTROLLER_CLASS_H
#define WORLDCONTROLLER_CLASS_H

#include <SFML/Graphics.hpp>
#include "models/Database.h"
#include "player/player.h"
#include "shaders/basicShader.h"
#include "textures/basicTexture.h"

class Application;

class WorldController {

    public:
        explicit WorldController(Application* app);
        ~WorldController();

        void Update(float deltaTime);
        void handleInput(float deltaTime);
        void handleScrollWheel(int steps);

        bool control_;
        float deltaTime;

        /*
            Sharing using for shader and texture
            we chosing shader and combine with with "model matrix" store on database
            and Player will provine "view maxtrix * projection" matrix
        */
        void addNewShader(char* vertexPath,char* fragPath , std::string name);
        void addNewTexture(const std::string& file, char* type, std::string name);

    protected:
        /* hold state from parent  */
        Application* m_pApplication;

        /* hold start of child instance */
        Player* m_pPlayer;
        Database*  m_pDatabase;
        std::vector<BasicShader>  using_shaders;
        std::vector<Texture>  using_textures;

};


#endif
