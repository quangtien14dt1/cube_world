#include "worldController.h"



void WorldController::FocusCallback(GLFWwindow *window, int focused)
{
	auto target = (WorldController*)glfwGetWindowUserPointer(window);
	if(!focused)
		target->control_ = false;
}

void WorldController::FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
	auto target = (WorldController*)glfwGetWindowUserPointer(window);
	target->Resize(width, height);
}

void WorldController::KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	auto target = (WorldController*)glfwGetWindowUserPointer(window);
}

void WorldController::ScrollCallback(GLFWwindow *window, double x_offset, double y_offset)
{
    auto target = (WorldController*)glfwGetWindowUserPointer(window);

}


WorldController::WorldController(GLFWwindow *window) : m_pWindow(window)
{

    m_pPlayer = new Player(this);
    m_pDatabase = new Database();
    m_pFrameRate = new Framerate();

	glfwSetWindowUserPointer(window, (void*)this);

	glfwSetWindowFocusCallback(window, FocusCallback);
	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetScrollCallback(window, ScrollCallback);

	int width, height;
	glfwGetFramebufferSize(m_pWindow, &width, &height);
	Resize(width, height);

}

WorldController::~WorldController() {
    if(m_pPlayer != nullptr) {
        delete m_pPlayer;
    }
    if(m_pDatabase != nullptr) {
        delete m_pDatabase;
    }
    if(m_pFrameRate != nullptr) {
        delete m_pFrameRate;
    }

}

void WorldController::Resize(int width, int height)
{
	width_ = width;
	height_ = height;
	glViewport(0, 0, width, height);
	glfwSetCursorPos(m_pWindow, width / 2, height / 2);
}

void WorldController::Update() {
    m_pFrameRate->Update();
}
