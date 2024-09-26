#pragma once
#include "renderer/shader.h"
#include "renderer/mesh.h"
#include "renderer/camera.h"
#include <unordered_map>
#include "GLFW/glfw3.h"

class Renderer
{
public:
	void initialize();
	void render();

	bool isOpen() { return !glfwWindowShouldClose(window); }
private:
	std::unordered_map<const char*, Shader> shaders;
	std::unordered_map<unsigned int, ChunkMesh> chunks;

	void initializeWindow();
	void initializeRenderer();
	void initializeShaders();
	
	void renderChunks();

	GLFWwindow* window;
	Camera* camera;

	glm::vec2 resolution;
};