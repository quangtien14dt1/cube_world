#include <iostream>
#include "math.h"
#include "application.h"


int main() {
    try
    {
        Application app;
        app.runLoop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
