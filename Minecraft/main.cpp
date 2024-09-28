#include <iostream>
#include "src/engine.h"
#include "src/game.h"

int main()
{
	Engine engine;
	Game game(&engine);

	engine.run();
	game.start();

	while(engine.renderer->isOpen())
	{
		engine.update();
		game.update();
	}
	return 0;
}