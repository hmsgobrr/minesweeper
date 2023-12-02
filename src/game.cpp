#include "Game.h"

#include "pt/Log.h"

#include <cmath>

Game::Game(int p_SCREEN_SIZE, int p_TILESW):
    SCREEN_SIZE(p_SCREEN_SIZE),
    TILESW(p_TILESW),
    TILE_SIZE(SCREEN_SIZE/TILESW) {

	even = { 0.8f, 0.8f, 0.8f, 1.0f };
	odd = { 0.2f, 0.2f, 0.2f, 1.0f };
	evenHover = { 0.7f, 0.7f, 0.7f, 1.0f };
	oddHover = { 0.1f, 0.1f, 0.1f, 1.0f };

    numbersTex.createFromFile(ASSETS_PATH"numeros.png", true);
}

void Game::Start() {}

void Game::Update() {
    // convert mouse position into tile position
    hoveredTileX = floor(pt::getMousePosition().x/SCREEN_SIZE*(float)TILESW);
    hoveredTileY = floor(pt::getMousePosition().y/SCREEN_SIZE*(float)TILESW);
    hoveredTileIsumJ = hoveredTileX + TILESW*hoveredTileY;
}

void Game::Draw() {
    for (int i = 0; i < TILESW; i++) {
        for (int j = 0; j < TILESW; j++) {
            int tileId = j + TILESW*i; // order of tile
            pt::Color& evenColor = tileId == hoveredTileIsumJ ? evenHover : even;
            pt::Color& oddColor = tileId == hoveredTileIsumJ ? oddHover : odd;
            pt::Color& tileColor = (i+j)%2 == 0 ? evenColor : oddColor;

            pt::drawRect(
                { (float)(TILE_SIZE*j), (float)(TILE_SIZE*i), (float)TILE_SIZE, (float)TILE_SIZE },
                0, tileColor
            );
        }
    }

    pt::drawTexture(
        numbersTex,
        { 0.0f, 0.0f, 0.25f, 0.5f },
        { 0.0f, 0.0f, (float)TILE_SIZE, (float)TILE_SIZE },
        0.0f, { 1.0f, 1.0f, 1.0f, 1.0f }
    );
}
