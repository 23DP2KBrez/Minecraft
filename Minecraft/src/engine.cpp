#include "engine.h"

void Engine::run()
{
	renderer.initialize();

	while (renderer.isOpen())
	{
		renderer.render();
	}
}

