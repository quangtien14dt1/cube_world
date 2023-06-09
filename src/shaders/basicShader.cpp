#include "basicShader.h"
#include "shader_utils.h"

BasicShader::~BasicShader() {
    glDeleteProgram(m_shaderProgram);
}


BasicShader::BasicShader(
                            const std::string & vertexPath,
                            const std::string & fragPath    ) {

    m_shaderProgram = 0;
    // file name by key , code read from by value
    const std::string BasicShaderCodes[2] = {   loadFile(vertexPath),
                                                loadFile(fragPath) };

    const std::string filenames[2] = { vertexPath,
                                       fragPath};

    // read file content
    GLuint vertexBasicShaderId;
    GLuint fragmentBasicShaderId;
    for (int index = 0; index < sizeof(BasicShaderCodes) / sizeof(std::string); ++index) {
        /* checking if BasicShaderCode string is empty */
        if (BasicShaderCodes[index].empty()) {
            continue;
        }
        // std::cout << BasicShaderCodes[index].c_str() << std::endl;

        if(index == 0) {
            vertexBasicShaderId = compileShader(BasicShaderCodes[index].c_str(), GL_VERTEX_SHADER);
        }else{
            fragmentBasicShaderId = compileShader(BasicShaderCodes[index].c_str(), GL_FRAGMENT_SHADER);
        }
    }

    /*
        linking and delete after
    */
    m_shaderProgram = linkProgram(vertexBasicShaderId, fragmentBasicShaderId);
}


/*
    functions usage
*/
void BasicShader::loadInt(GLuint location, int value)
{
    glUniform1i(location, value);
}
void BasicShader::loadFloat(GLuint location, float value)
{
    glUniform1f(location, value);
}

void BasicShader::loadVector2(GLuint location, const glm::vec2& vect)
{
    glUniform2f(location, vect.x, vect.y);
}

void BasicShader::loadVector3(GLuint location, const glm::vec3& vect)
{
    glUniform3f(location, vect.x, vect.y, vect.z);
}

void BasicShader::loadVector4(GLuint location, const glm::vec4& vect)
{
    glUniform4f(location, vect.x, vect.y, vect.z, vect.w);
}

void BasicShader::loadMatrix4(GLuint location, const glm::mat4& matrix)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

/*
    shader
*/
void BasicShader::Activate() {
    if (m_shaderProgram != 0) {
        glUseProgram(m_shaderProgram);
    }
}

void BasicShader::Delete() {
    glDeleteProgram(m_shaderProgram);
}


GLuint BasicShader::getUniformLocation(const std::string & uniform_name){
    Activate();
    GLuint location  = glGetUniformLocation(m_shaderProgram, "projViewMatrix");
    return location;
}
