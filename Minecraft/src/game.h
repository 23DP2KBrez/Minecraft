#pragma once
#include "engine.h"
#include "modules/renderer/camera.h"
#include "game/chunk.h"

enum states
{
	MAIN_MENU,
	GAMEPLAY,
	PAUSE_MENU,
	OPTIONS_MENU,
	LOADING
};

class Game
{
public:
	Game(Engine* engine) : engine(engine) {}
	~Game();
	void start();
	void update();

	states state = GAMEPLAY;

	Camera* camera;
	InputManager* inputManager;

	void setBlock(int block, glm::vec3 position);
private:
	void input();
	Engine* engine;
	void processEscape();
};