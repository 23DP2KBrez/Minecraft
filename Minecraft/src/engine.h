#pragma once
#include "modules/audio.h"
#include "modules/renderer.h"
#include "modules/InputManager.h"


class Engine
{
public:
	Engine();
	~Engine();
	void run();
	void update();

	Renderer* renderer;
	Audio* audio;
private:

};