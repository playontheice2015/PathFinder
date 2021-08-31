#include "APathFinder.h"
#include <iostream>
#include "Board.h"

APathFinder::APathFinder(Board* board): board(board)
{
	searchList.push_back(board->start);
}

APathFinder::~APathFinder()
{}

int APathFinder::findPath() {
	if (this->board == nullptr)
		return -1;
	else if (board->start->x == board->target->x && 
				board->start->y == board->target->y)
		return 0;
	
	previousTile = this->board->start;
	while (searchList.size() > 0)
	{
		if (searchList.size() > 0) {
			int topInx = 0;
			for (size_t i = 0; i < searchList.size(); i++)
			{
				if (searchList[i]->f < searchList[topInx]->f)
					topInx = i;
				if (searchList[i]->f == searchList[topInx]->f) {
					// if f is equal thn find closer g
					if (searchList[i]->g > searchList[topInx]->g) {
						topInx = i;
					}
				}
			}
			Tile* currentTile = searchList[topInx];
			previousTile = currentTile;
			if (currentTile == board->target) {
				std::cout << "\n Path to target is found!";
				return getFoundPaths(currentTile,board->pOutBuffer,board->nOutBufferSize);
			}
			if (currentTile->isVisited) {
				eraseFromList(searchList, currentTile);
				continue;
			}
			currentTile->isVisited = true;
			eraseFromList(searchList, currentTile);
			closedList.push_back(currentTile);
			currentTile->initNeighbours();
			for (size_t i = 0; i < currentTile->neighbours.size() ; i++) {
				Tile* neighbour = currentTile->neighbours[i];
					if(!neighbour->isWall && !contains(closedList, neighbour)) {
						auto tmpG = currentTile->g + heuristicCalc(neighbour, currentTile);
						// check if we try this before
						if (!contains(searchList, neighbour)) {
							searchList.push_back(neighbour);
						}
						else if (tmpG >= neighbour->g) {
							continue; // if there isnt a shorter path
						}
						neighbour->g = tmpG;
						neighbour->h = heuristicCalc(neighbour, board->target);
						neighbour->f = neighbour->g + neighbour->h;
						neighbour->cameFrom = currentTile;
					}
			}
		}
	}
	return -1;
};

// setting found points to "outbutbuffer" and points count 
// finding connected nodes by cameFom recursively from lastPoint
int APathFinder::getFoundPaths(Tile* lastPoint, int* pOutBuffer,const int nOutBufferSize ) {
	Tile* tmp = lastPoint;
	int i = 0;
	pOutBuffer[i++]= int(tmp->x + (tmp->y * tmp->board->cols));
	while (tmp->cameFrom != lastPoint->board->start)
	{
		tmp = tmp->cameFrom;
		pOutBuffer[i++] = int(tmp->x + (tmp->y * tmp->board->cols));
	}
	
	return i;
}

// Manhaten block style
// in future: if diagnol neighbours needed this method should should dev.
float heuristicCal(Tile* startPoint, Tile* targetPoint) {
	return  abs(startPoint->x - targetPoint->x) + abs(startPoint->y - targetPoint->y);
}

bool APathFinder::contains(std::vector<Tile*> list, Tile* element)
{
	return (std::find(list.begin(), list.end(), element) != list.end());
}

void APathFinder::eraseFromList(std::vector<Tile*> &list, Tile* element)
{
	auto e = std::find(list.begin(), list.end(), element);
	if (e != list.end()) {
		list.erase(e);
	}
}

float APathFinder::heuristicCalc(Tile * startPoint, Tile * targetPoint)
{
	return abs(startPoint->x - targetPoint->x) + abs(startPoint->y - targetPoint->y);
}
