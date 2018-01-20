#include "stdafx.h"
#include "Board.h"
Board::Board()
{
	
	for (int i = 0; i < 8; i++)
	{
		whiteRows[i] = 1;
		blackRows[i] = 1;
	}
	for (int i = 0; i < 8; i++)
	{
		whiteRows[0] *= COLUMNS[i];
		whiteRows[1] *= COLUMNS[i];
		blackRows[6] *= COLUMNS[i];
		blackRows[7] *= COLUMNS[i];
	}
}


Board::~Board()
{
}

bool Board::makeMove(bool playerWhite, int oldRow, int oldColumn, int row, int column)
{
	//to do:the array values should be put into temp variable so they dont have to be accessed again

	//bound checking
	if (oldRow < 0 || oldRow > 7 || oldColumn < 0 || oldColumn > 7) 
	{
		return false;
	}

	if (row < 0 || row > 7 || column < 0 || column > 7) 
	{
		return false;
	}
	//only allows diagonal move or forward move
	if (column < oldColumn - 1 || column > oldColumn + 1)
	{
		return false;
	}

	if (playerWhite)
	{
		if (row != oldRow + 1)
		{
			return false;
		}

		if (whiteRows[oldRow] % COLUMNS[oldColumn] != 0) {
			return false;
		}

		if (whiteRows[row] % COLUMNS[column] == 0)
		{
			return false;
		}

		if (column == oldColumn && blackRows[row] % COLUMNS[column] == 0)
		{
			return false;
		}

		if (blackRows[row] % COLUMNS[column] == 0)
		{
			blackRows[row] /= COLUMNS[column];
			blackCount--;
		}

		if (row == 7 || blackCount == 0)
		{
			gameOver = true;
		}

		whiteRows[oldRow] /= COLUMNS[oldColumn];
		whiteRows[row] *= COLUMNS[column];
	}

	if (!playerWhite) 
	{
		//allows only move down one row at time
		if (row != oldRow - 1)
		{
			return false;
		}
		//is there a black piece already at new position
		if (blackRows[row] % COLUMNS[column] == 0)
		{
			return false;
		}
		//is there a black piece to be moved from old position
		if (blackRows[oldRow] % COLUMNS[oldColumn] != 0) {
			return false;
		}
		//prevent piece from moving forward if white piece is in way
		if (column == oldColumn && whiteRows[row] % COLUMNS[column] == 0)
		{
			return false;
		}
		//if piece of white was taken
		if (whiteRows[row] % COLUMNS[column] == 0)
		{
			whiteRows[row] /= COLUMNS[column];
			whiteCount--;
		}

		if (row == 0 || whiteCount == 0)
		{
			gameOver = true;
		}

		blackRows[oldRow] /= COLUMNS[oldColumn]; //remove piece at old position
		blackRows[row] *= COLUMNS[column]; //add piece at new position
	}

	return true;
}

bool Board::isGameOver()
{
	if (gameOver)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char Board::getPieceAt(int row, int column)
{
	if (whiteRows[row] % COLUMNS[column] == 0)
	{
		return 'W';
	}
	else if (blackRows[row] % COLUMNS[column] == 0)
	{
		return 'B';
	}
	else
	{
		return ' ';
	}
}

//this return can be changed based what Player class needs 
unsigned int* Board::getBlackPieces()
{
	static unsigned int temp[8];
	for (int row = 0; row < 8; row++)
	{
		temp[row] = blackRows[row];
	}
	return temp;
}

unsigned int* Board::getWhitePieces()
{
	static unsigned int temp[8];
	for (int row = 0; row < 8; row++)
	{
		temp[row] = whiteRows[row];
	}
	return temp;
}

