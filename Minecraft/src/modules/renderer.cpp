#include "renderer.h"

void Renderer::initialize()
{
	initializeWindow();
	initializeRenderer();
	initializeShaders();

	resolution = glm::vec2(800, 600);
	camera = new Camera(89.0f, resolution);
	camera->position = glm::vec3(10, 0, 25);
	camera->rotation = glm::vec3(0, 0, 0);

	uint8_t* blocks = new uint8_t[4096];
	memset(blocks, 0, 4096);
	blocks[2] = 1;

	ChunkMesh mesh(blocks);
	chunks[0] = mesh;
	chunks[0].createMesh();
}

void Renderer::initializeWindow()
{
	glfwInit();
	window = glfwCreateWindow(800, 600, "Minecraft", nullptr, nullptr);

	glfwMakeContextCurrent(window);
}

void Renderer::initializeRenderer()
{
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, 800, 600);
	glEnable(GL_DEPTH_TEST);
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

	renderChunks();

	glfwSwapBuffers(window);

	glfwPollEvents();
}

void Renderer::renderChunks()
{
	glUseProgram(shaders["terrain"].getId());

	glm::mat4 vp = camera->getProjectionMatrix() * camera->getViewMatrix();
	shaders["terrain"].setMat4("MVP", vp * chunks[0].getModelMatrix());
	chunks[0].renderMesh();
}