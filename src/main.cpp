#include "pt/plankton.h"
#include "pt/Log.h"

#include "Game.h"

#define SCREEN_SIZE 600

#ifndef ASSETS_PATH
#define ASSETS_PATH ""
#endif

#define TILESW 20

int main() {
	pt::initWindow(SCREEN_SIZE, SCREEN_SIZE, "megusta");

	Game game(SCREEN_SIZE, TILESW);

	game.Start();

	while (!pt::windowShouldClose()) {
		pt::prepareFrame();

		if (pt::isKeyPressed(pt::Key::KEY_ESCAPE)) pt::closeWindow();

		game.Update();

		pt::clearFrame({ 0.1f, 0.1f, 0.1f, 0.1f });
		
		game.Draw();

		pt::display();
	}

	pt::shutdown();
	
	return 0;
}
