#pragma once
class Board
{

public:
	Board();
	~Board();
	//maybe should add a contains method
	bool makeMove(bool, int, int, int, int);
	bool isGameOver();
	char getPieceAt(int, int);
	unsigned int* getWhitePieces();
	unsigned int* getBlackPieces();
private:
	int blackCount = 16;
	int whiteCount = 16;
	bool gameOver = false;
	unsigned int blackRows[8];
	unsigned int whiteRows[8];
	const int COLUMNS[8] = { 2, 3, 5, 7, 11, 13, 17, 19 };	//A-H
};

