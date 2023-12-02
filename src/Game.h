#ifndef GAME_H
#define GAME_H

#include "pt/plankton.h"

class Game {
public:
    Game(int p_SCREEN_SIZE, int p_TILESW);

    void Start();
    void Update();
    void Draw();
private:
    const int SCREEN_SIZE, TILESW, TILE_SIZE;
    pt::Texture numbersTex;
	pt::Color even;
	pt::Color odd;
	pt::Color evenHover;
	pt::Color oddHover;

    int hoveredTileX;
    int hoveredTileY;
    int hoveredTileIsumJ;
};

#endif // GAME_H
