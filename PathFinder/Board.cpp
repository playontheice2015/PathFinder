#include "Board.h"
#include <iostream>

Board::Board()
{}

Board::~Board()
{
	delete[] tiles;
}

void Board::init(
	const int nStartX, const int nStartY,
	const int nTargetX, const int nTargetY,
	const unsigned char pMap[], 
	const int nMapWidth, const int nMapHeight,
	int* pOutBuffer, const int nOutBufferSize) {
		this->cols = nMapWidth;
		this->rows = nMapHeight;
		this->tiles = new Tile*[rows];
		for (int row = 0; row < rows; row++) {
			tiles[row] = new Tile[cols]; 
		}
		this->pOutBuffer = pOutBuffer;
		this->nOutBufferSize = nOutBufferSize;
		setDetails(nStartX,nStartY,nTargetX,nTargetY,pMap);
}

void Board::setDetails(const int nStartX, const int nStartY,
	const int nTargetX, const int nTargetY,
	const unsigned char pMap[]) {
	int arrayInx = 0;
	this->start = &(tiles[nStartY][nStartX]);
	this->target = &(tiles[nTargetY][nTargetX]);

	for (size_t r = 0; r < this->rows; r++)
		for (size_t c = 0; c < this->cols; c++)
		{
			tiles[r][c].x = c;
			tiles[r][c].y = r;
			tiles[r][c].isWall = !pMap[arrayInx];
			tiles[r][c].board = this;
			arrayInx++;
		}
}

void Board::draw()
{ 
	std::cout << "\n Map size " << rows << "x" << cols <<  std::endl;
		size_t arrayInx = 0;
		for (size_t r = 0; r < this->rows; r++)
		{
		 	for (size_t c = 0; c < this->cols; c++)
			{
				if (start->y == r && start->x == c) {
					std::cout << "[" << '>' << "]";
				}
				else if (target->y == r && target->x == c) {
					std::cout << "[" << '$' << "]";
				}
				else if (contains(this->pOutBuffer, c  + (r*cols))) {
					std::cout << "[" << '.' << "]";
				}
				else {
					std::cout << "[" << (( tiles[r][c].isWall) ? '#' : ' ') << "]";
				}
				arrayInx++;
			}
			std::cout << "\n";
		}
		for (size_t i = 0; i < nOutBufferSize; i++)
		{
			if (pOutBuffer[i]>-1)
			std::cout << pOutBuffer[i] << ",";
		}
}
 
bool Board::contains(int* arrPoints, int nPoint)
{
	if (arrPoints == nullptr)
		return false;
	int n = sizeof(arrPoints) / sizeof(arrPoints[0]);
	auto it = std::find(arrPoints, arrPoints + n, nPoint);
	for (size_t i = 0; i < nOutBufferSize; i++)
	{
		if (arrPoints[i] == nPoint)
			return true;
	}
	return ( it != (arrPoints+n));
}