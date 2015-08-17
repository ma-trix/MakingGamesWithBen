#include <iostream>
#include <string>

using namespace std;

class CheckerBoard
{
public:
	void initBoard()
	{
		char black = '.';
		char white = '*';
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if ((y + x) % 2 == 0)
					board[y][x] = black;
				else
				{
					board[y][x] = white;
				}
			}
		}
	}

	void printBoard()
	{
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				cout << board[y][x];
			}
			cout << endl;
		}
	}
private:
	char board[8][8];
};

int main()
{
	CheckerBoard board;

	board.initBoard();
	board.printBoard();

	system("PAUSE");
	return 0;
}