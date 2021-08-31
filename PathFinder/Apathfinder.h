#pragma once

#include <vector>
#include "Tile.h"

class APathFinder
{
public:
	APathFinder(Board* board);
	~APathFinder(
	);

 	/**
	APathFinder(Tile* start, Tile* target){
	m_start = start;
	m_target = target;
	m_board = start->board;
	}
	*/
	int findPath();
	int getFoundPaths(Tile * lastPoint, int * pOutBuffer, const int nOutBufferSize);
	Board* board;
private:
	std::vector<Tile*> searchList;
	std::vector<Tile*> closedList;
	Tile* previousTile;
	bool contains(std::vector<Tile*> list, Tile* element);
	float heuristicCalc(Tile* startPoint, Tile* targetPoint);
	void eraseFromList(std::vector<Tile*> &list, Tile* element);
};

