#pragma once
#include "Tile.h"

class Board
{

public:
	Tile** tiles;
	size_t rows;
	size_t cols;
	void draw();
	void drawPath(std::vector<Tile*> foundPathArr);
	void init(const int nStartX, const int nStartY,
		const int nTargetX, const int nTargetY,
		const unsigned char pMap[], const int nMapWidth, const int nMapHeight,
		int* pOutBuffer, const int nOutBufferSize
		);

	Board();
	~Board();

	Tile* start;
	Tile* target;
	int* pOutBuffer;
	int nOutBufferSize;
protected:
	//bool contains(std::vector<Tile*> list, Tile * element);
	bool contains(int* arrPoints, int nPoint);
	void setDetails(const int nStartX, const int nStartY,
		const int nTargetX, const int nTargetY,
		const unsigned char pMap[]);
};


