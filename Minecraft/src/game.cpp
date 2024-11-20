#include "game.h"
#include <iostream>
#include <thread>
#include "modules/renderer/camera.h"

Game::~Game()
{
	delete camera;
	delete inputManager;
}

void Game::start()
{
	inputManager = new InputManager(engine->renderer->window);

	camera = new Camera(89.0f, engine->renderer->getResolution());
	camera->position = glm::vec3(0.0f, 0.0f, 0.0f);
	camera->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	engine->renderer->camera = camera;
	inputManager->lockCursor(true);
	inputManager->bindKey(GLFW_KEY_ESCAPE, std::bind(&Game::processEscape, this));

	Chunk chunk;
	
	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			for (int z = 0; z < 15; z++)
			{
				chunk.blocks[getBlockIndex(x, y, z)] = y <= ((sin(x * 0.6f) * 0.5f + 0.5f) * 10) ? 7 : 0;
			}
		}
	}

	chunk.mesh->createMesh();
	engine->renderer->meshArray.push_back(chunk.mesh);
}

void Game::update()
{
	input();
}

void Game::input()
{
	inputManager->update();
	if (inputManager->onMouseClick(GLFW_MOUSE_BUTTON_LEFT) && state != GAMEPLAY)
	{
		inputManager->lockCursor(true);
		inputManager->setCursorPos(glm::vec2(1920 / 2, 1080 / 2));
		state = GAMEPLAY;
	}

	if (state == GAMEPLAY)
	{
		glm::vec2 cursorPos = inputManager->getCursorPos();
		camera->rotation.y += -((1920 / 2 - cursorPos.x) * 0.1f);
		camera->rotation.x += -((1080 / 2 - cursorPos.y) * 0.1f);
		inputManager->setCursorPos(glm::vec2(1920 / 2, 1080 / 2));
	}

	glm::vec3 left = glm::vec3(
		cos(glm::radians(camera->rotation.y)) * cos(glm::radians(camera->rotation.x)),
		sin(glm::radians(camera->rotation.x)),
		sin(glm::radians(camera->rotation.y)) * cos(glm::radians(camera->rotation.x))
	);

	if (inputManager->onKeyPress(GLFW_KEY_A))
	{
		camera->position += -left * 0.1f;
	}
	if (inputManager->onKeyPress(GLFW_KEY_D))
	{
		camera->position += left * 0.1f;
	}
}

void Game::processEscape()
{
	if (state == GAMEPLAY)
	{
		inputManager->lockCursor(false);
		state = PAUSE_MENU;
	}
}

void Game::setBlock(int block, glm::vec3 position)
{
	int x = (int)position.x;
	int y = (int)position.y;
	int z = (int)position.z;
}