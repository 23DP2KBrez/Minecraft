#pragma once
#include "renderer/shader.h"
#include "renderer/mesh.h"
#include "renderer/camera.h"
#include "renderer/texture.h"
#include <unordered_map>
#include "GLFW/glfw3.h"

class Renderer
{
public:
	void initialize();
	void render();

	bool isOpen() { return !glfwWindowShouldClose(window); }

	GLFWwindow* window;

	Camera* camera;
	glm::vec2 getResolution() { return glm::vec2(800, 600); }

	std::vector<Mesh*> meshArray;
private:
	std::unordered_map<const char*, Shader> shaders;


	void initializeWindow();
	void initializeRenderer();
	void initializeShaders();
	
	void renderMeshes();

	TextureAtlas chunkTexture;
};