#include "renderer.h"

void Renderer::initialize()
{
	initializeWindow();
	initializeRenderer();
	initializeShaders();
}

void Renderer::initializeWindow()
{
	glfwInit();
	window = glfwCreateWindow(1920, 1080, "Minecraft", nullptr, nullptr);

	glfwMakeContextCurrent(window);
}

void Renderer::initializeRenderer()
{
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, 1920, 1080);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	chunkTexture.load("assets/textures/terrain.png");

}

void Renderer::initializeShaders()
{
	Shader terrain;
	terrain.loadShader("assets/shaders/terrain.vsh", GL_VERTEX_SHADER);
	terrain.loadShader("assets/shaders/terrain.fsh", GL_FRAGMENT_SHADER);
	terrain.create();
	shaders["terrain"] = terrain;
}

void Renderer::render()
{
	glClearColor(0.2f, 0.5f, 0.5f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	renderMeshes();

	glfwSwapBuffers(window);

	glfwPollEvents();
}

void Renderer::renderMeshes()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, chunkTexture.getId());

	glUseProgram(shaders["terrain"].getId());

	Mesh* mesh = meshArray[0];
	glm::mat4 vp = camera->getProjectionMatrix() * camera->getViewMatrix();
	shaders["terrain"].setMat4("MVP", vp * mesh->getModelMatrix());
	mesh->renderMesh();
}