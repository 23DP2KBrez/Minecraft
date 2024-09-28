#include "engine.h"
#include <thread>

Engine::Engine()
{
	renderer = new Renderer();
	audio = new Audio();
}

Engine::~Engine()
{
	delete renderer;
	delete audio;
}

void Engine::run()
{
	renderer->initialize();
}

void Engine::update()
{
	renderer->render();
}
