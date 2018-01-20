


#include <iostream>
#include "Board.h"
using namespace std;

void display(Board t)
{
	cout << endl << endl;
	const int COLUMNS[8] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	for (int row = 7; row >= 0; row--)
	{
		cout << row << ' ';
		for (int column = 0; column < 8; column++)
		{
			unsigned int* whitePieces = t.getWhitePieces();
			unsigned int* blackPieces = t.getBlackPieces();
			
			if (whitePieces[row] % COLUMNS[column] == 0)
			{
				cout << 'W';
			}
			else if (blackPieces[row] % COLUMNS[column] == 0)
			{
				cout << 'B';
			}
			else
				cout << 'E';
		}
		cout << endl;
	}
	cout << "  ";
	for (int i = 0; i < 8; i++)
	{
		cout << i;
	}
	cout << endl;
}
int main()
{
	Board breakthrough{};
	display(breakthrough);
	bool t = true;
	int x1, y1;
	int x2, y2;
	while (!breakthrough.isGameOver())
	{
		do
		{
			cout << "make move" << endl;
			cin >> x1 >> y1;
			cin >> x2 >> y2;
		} while (!breakthrough.makeMove(t, x1, y1, x2, y2));
		
		t = !t;
		display(breakthrough);
	}
    return 0;
}

