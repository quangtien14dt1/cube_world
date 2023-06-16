#ifndef FRAMERATE_CLASS_H
#define FRAMERATE_CLASS_H

#include <GLFW/glfw3.h>

class Framerate {

    private:
        float delta_, fps_;
    public:
        Framerate();

        void Update();
        float GetFps();
        float GetDelta() const ;
};


#endif
