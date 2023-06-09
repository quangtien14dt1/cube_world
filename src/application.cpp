#include <helpers/RootDir.h>
#include "application.h"
#include "untils/fileSystem.h"


Vertex vertices[] = {
    // Vertex{glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
    // positions                           // normals
    Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f)},
    Vertex{glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f)},
    Vertex{glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f)},
    Vertex{glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f)},
    Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f)},

    Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f)},
    Vertex{glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f)},
    Vertex{glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f)},
    Vertex{glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f)},
    Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f)},

    Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f)},

    Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f,  0.0f,  0.0f)},
    Vertex{glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f,  0.0f,  0.0f)},

    Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f)},
    Vertex{glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f)},
    Vertex{glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f)},
    Vertex{glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f)},

    Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f)},
    Vertex{glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f)},
    Vertex{glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f)},
    Vertex{glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f)},
    Vertex{glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f)},
};

Application::Application() : width_(720), height_(480) {}

int Application::InitWindow()
{
    /* Initialize the library */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    window_ = glfwCreateWindow(width_, height_, "cube world! ", NULL, NULL);
    if (window_ == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make  the window's context current */
    glfwMakeContextCurrent(window_);

    /* Functions handle operation and input with window */
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // glfwSetCursorPosCallback(window, mouse_callback);
    // glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    // glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    /* Initialize glew api */
    if ( glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize Glew" << std::endl;
        return 1;
    }

    /* Set the viewport window */
    glClearColor(0.6784f, 0.8f, 1.0f, 1.0f);
    glViewport(0, 0, width_, height_);

    /* Enable for checking bit depth */
    glEnable(GL_DEPTH_TEST);

    return true;
}

void Application::loadContent() {

    /* Creat textures  */
    Texture textures[] = {
        Texture("container2.png", "diffuse"),
        Texture("container2.png", "diffuse")
    };

    // /* Camera */
    // glm::vec3 cam_position = glm::vec3(0.0f, 1.0f, 1.2f);
    // glm::vec3 cam_look_at  = glm::vec3(0.0f, 0.5f, 0.0f);
    // glm::vec3 cam_up       = glm::vec3(0.0f, 1.0f, 0.0f);

    // /* model view projection */
    // glm::mat4 world_matrix      = glm::mat4(1.0f);
    // glm::mat4 view_matrix       = glm::lookAt(cam_position, cam_look_at, cam_up);
    // glm::mat4 projection_matrix = glm::perspectiveFov(
    //     glm::radians(60.0f),
    //     float(width_),
    //     float(height_),
    //     0.1f,
    //     10.0f
    // );


    /* Create new Mesh */
    std::vector <Vertex> verts {vertices, vertices + sizeof(vertices) / sizeof(Vertex)};
	std::vector <Texture> tex {textures, textures + sizeof(textures) / sizeof(Texture)};
    Mesh Cube(verts, tex);

    /* Create and apply basic shader */
    BasicShader shaderProgram("basic.vert", "basic.frag");
    shaderProgram.Activate();
    glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view          = glm::mat4(1.0f);
    glm::mat4 projection    = glm::mat4(1.0f);
    model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
    view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(
                            glm::radians(45.0f),
                            (float)width_ / (float)height_, 0.1f, 100.0f);

    unsigned int modelLoc = glGetUniformLocation(shaderProgram.m_shaderProgram, "model");
    unsigned int viewLoc  = glGetUniformLocation(shaderProgram.m_shaderProgram, "view");
    unsigned int projLoc  = glGetUniformLocation(shaderProgram.m_shaderProgram, "projection");
    shaderProgram.loadMatrix4(modelLoc, model);
    shaderProgram.loadMatrix4(viewLoc, view);
    shaderProgram.loadMatrix4(projLoc, projection);

    /* Draw mes object */
    Cube.Draw(shaderProgram);
}

void  Application::render() {
    /* Clear buffer creen */
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    loadContent();
}

void Application::update()
{
    double  previousTime = glfwGetTime();
    int     frameCount = 0;
    float   gameTime = 0.0f;

    while (!glfwWindowShouldClose(window_))
    {
        /* Counting FPS block */
        double currentTime = static_cast<float>(glfwGetTime());
        gameTime = currentTime - previousTime;
        frameCount++;
        // If a second has passed.
        if ( gameTime >= 1.0 )
        {
            // Display the frame count here any way you want.
            // displayFPS(frameCount);

            frameCount = 0;
            previousTime = currentTime;
        }

        /* Render */
        render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window_);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

int Application::Run() {

    if(!InitWindow()) return -1;

    update();

    return 0;
}


Application::~Application() {
	glfwDestroyWindow(window_);
}
