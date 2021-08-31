#include <iostream>
#include <iomanip>
#include "Board.h"
#include "APathFinder.h"

//For test purpose 9x9 map with some walls
//pathfinder will first draw plain map than if path is found
//it will draw on screen and return required results
int main() {

#pragma region Test_Map4x5
//unsigned char pMap[] = { 
//	1, 1, 1, 1, 
//	0, 1, 0, 1,
//	0, 1, 0, 1,
//	0, 1, 1, 1,
//	0, 1, 1, 1 };

//const int nWidth = 4;
//const int nHeight = 5;
//const int startX = 1;
//const int startY = 0;
//const int targetX = 3;
//const int targetY = 4;
//const int nOutBufferSize = 20;
//int pOutBuffer[20];  
#pragma endregion

#pragma region Test_Map4x3
	//unsigned char pMap[] = { 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1 };
	//const int nWidth = 4;
	//const int nHeight = 3;
	//const int startX = 0;
	//const int startY = 0;
	//const int targetX = 1;
	//const int targetY = 2;
	//const int nOutBufferSize = 12;
	//int pOutBuffer[12];
#pragma endregion

#pragma region Test_Map3x3
	//unsigned char pMap[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1 };
	//const int nWidth = 3;
	//const int nHeight = 3;
	//const int startX = 2;
	//const int startY = 0;
	//const int targetX = 0;
	//const int targetY = 2;
	//const int nOutBufferSize = 7;
	//int pOutBuffer[7];  
#pragma endregion

#pragma region Test_Map9x9
	unsigned char pMap[] = { 
	1, 1, 1, 0, 1, 1, 1, 0, 1,
	1, 1, 0, 1, 1, 0, 1, 1, 1,
	0, 1, 1, 1, 1, 0, 0, 1, 1,
	0, 1, 1, 1, 1, 0, 1, 1, 1,
	1, 0, 0, 0, 0, 1, 1, 0, 0,
	0, 1, 1, 1, 0, 0, 1, 1, 1,
	1, 0, 1, 0, 0, 1, 1, 0, 0,
	0, 1, 0, 1, 1, 0, 1, 1, 1,
	1, 1, 1, 1, 1, 0, 0, 1, 1 };

	const int nWidth = 9;
	const int nHeight = 9;
	const int startX = 0;
	const int startY = 0;
	const int targetX = 8;
	const int targetY = 8;
	const int nOutBufferSize = 81;
	int pOutBuffer[81];  
#pragma endregion

	auto board = Board();
	board.init( startX, startY, targetX, targetY,
		pMap, nWidth, nHeight, pOutBuffer, nOutBufferSize );
	board.draw(); // plain draw to see the map board

	auto pathFinder = new APathFinder( &board );
	auto res = pathFinder->findPath();
	board.draw(); // result draw to see path

	std::cout << "\nA* path search result:" << res << std::endl;
	std::cin.get();
	
	delete pathFinder;
	return 0;
}

  