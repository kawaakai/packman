#include <iostream>
#include <conio.h> // for getch()

using namespace std;

int main() {
	bool flag = true;
	int scrore = 0;
	const int ROWS = 10;
	const int COLS = 20;
	int x = 1; // Pac-Man's x position
	int y = 1; // Pac-Man's y position
	char board[ROWS][COLS] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',	'#'},
		{'#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
		{'#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
		{'#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	};

	while (flag) {
		// Clear the console
		system("cls");

		// Draw the board
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				if (j == x && i == y)
				{
					cout << '@';
				}
				else {
					cout << board[i][j];
				}
			}
			cout << endl;
		}
		cout << scrore;
		char input = _getch();// Get the user's input
		switch (input) {
		case 'q':
			flag = false;
			break;
		case 'w':
			if (board[y - 1][x] != '#') {
				if (board[y - 1][x] == '.') {
					scrore++;
					board[y - 1][x] = ' ';
				}
				y--;
			}
			break;
		case 'a':
			if (board[y][x - 1] != '#') {
				if (board[y][x - 1] == '.') {
					scrore++;
					board[y][x - 1] = ' ';
				}
				x--;
			}
			break;
		case 's':
			if (board[y + 1][x] != '#') {
				if (board[y + 1][x] == '.') {
					scrore++;
					board[y + 1][x] = ' ';
				}
				y++;
			}
			break;
		case 'd':
			if (board[y][x + 1] != '#') {
				if (board[y][x + 1] == '.') {
					scrore++;
					board[y][x + 1] = ' ';
				}
				x++;
			}
			break;
		}
		if (scrore == 81) {
			flag = false;
		}
	}

	return 0;
}