#ifndef GAME_H
#define GAME_H

#include "pt/plankton.h"

#define SCREEN_SIZE 600
#define TILESW      20
#define TILE_SIZE   SCREEN_SIZE/TILESW
#define BOMBAS      40

enum TileState {
    BOMB
};

class Game {
public:
    Game();

    void Start();
    void Update();
    void Draw();
private:
    pt::Texture numbersTex;
	pt::Color even;
	pt::Color odd;
	pt::Color evenHover;
	pt::Color oddHover;

    TileState map[TILESW][TILESW];

    pt::Vector2Int hoveredTile;
    int hoveredTileIsumJ;
};

#endif // GAME_H
