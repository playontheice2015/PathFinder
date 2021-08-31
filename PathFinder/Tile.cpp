#include "Tile.h"
#include "Board.h"
#include <vector>

Tile::Tile(Board* board ) : board(board)
{}

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::initNeighbours()
{
	if (this->neighbours.size() > 0)
		return;

	int col = x;
	int row = y;
	int cols = board->cols;
	int rows = board->rows;

	if (col > 0)
		this->neighbours.push_back( &(this->board->tiles[row][col - 1]));
	if (col < cols - 1)
		this->neighbours.push_back( &(this->board->tiles[row][col + 1]));
	if (row < rows - 1)
		this->neighbours.push_back( &(this->board->tiles[row + 1][col]));
	if (row > 0)
		this->neighbours.push_back( &(this->board->tiles[row - 1][col]));
}