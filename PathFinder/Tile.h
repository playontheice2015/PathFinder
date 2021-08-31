#pragma once
#include <vector>

class Board;
class Tile
{
public:
	int x, y;
	bool isWall = false;
	float f = 0;
	float g = 0;
	float h = 0; //heuristic
	bool isVisited = false;
 	Board* board;
	void initNeighbours();
	std::vector<Tile*> neighbours;
	Tile* cameFrom;
	Tile(Board* board);
	Tile();
	~Tile();
};
