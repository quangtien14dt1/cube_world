#include "basicShader.h"

Shader::Shader(
    const std::string & vertexPath,
    const std::string & fragPath
)
{
    m_shaderProgram = 0;
    // file name by key , code read from by value
    const std::string shaderCodes[2] = {
                    shaderUntil::loadFile(vertexPath),
                    shaderUntil::loadFile(fragPath)
    };

    const std::string filenames[2] = { vertexPath,
                                       fragPath};

    // read file content
    GLuint vertexShaderId;
    GLuint fragmentShaderId;
    for (int index = 0; index < sizeof(shaderCodes) / sizeof(std::string); ++index) {
        /* checking if shaderCode string is empty */
        if (shaderCodes[index].empty()) {
            continue;
        }
        // std::cout << shaderCodes[index].c_str() << std::endl;

        if(index == 0) {
            vertexShaderId = shaderUntil::compileShader(shaderCodes[index].c_str(), GL_VERTEX_SHADER);
        }else{
            fragmentShaderId = shaderUntil::compileShader(shaderCodes[index].c_str(), GL_FRAGMENT_SHADER);
        }
    }

    /*
        linking and delete after
    */
    m_shaderProgram = shaderUntil::linkProgram(vertexShaderId, fragmentShaderId);
}
