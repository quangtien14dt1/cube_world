#include "shader_utils.h"

std::string loadFile(const std::string& filename){
    if (filename.empty()) {
        std::cout << " there is no file path provied" << std::endl;
        return "";
    }

    std::string     filetext;
    std::string     line;
    std::ifstream   inFile(ROOT_DIR "resources/shaders/" + filename);

    // checking if create success
    if (!inFile) {
        inFile.close();
        return "";
    }
    else {
        while (getline(inFile, line)) {
            filetext.append(line + "\n");
        }
        inFile.close();
        return filetext;
    }
};

GLuint compileShader(const GLchar *source, GLenum shaderType){
    /*
    if this create Segment Fault then checking for glfwInit()
    it have to init before create shader
    */
    GLuint shaderID = glCreateShader(shaderType);

    glShaderSource(shaderID, 1, &source, nullptr);
    glCompileShader(shaderID);

    GLint isSuccess = 0;
    GLchar infoLog[512];

    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isSuccess);
    if (!isSuccess) {
        glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
        throw std::runtime_error("UNABLE TO LOAD SHADER : " +
                                std::string(infoLog));
    }

    return shaderID;
};

GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID) {

    GLuint id = glCreateProgram();
    glAttachShader(id, vertexShaderID);
    glAttachShader(id, fragmentShaderID);

    glLinkProgram(id);

    /* delete vertext , fragment */
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    return id;
};
