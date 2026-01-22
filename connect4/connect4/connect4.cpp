#include <iostream>
#include <array>
#include <cctype>

using namespace std;

const int NUM_COLS = 7;
const int NUM_ROWS = 6;

using Row = array<char, NUM_COLS>;
using Table = array<Row, NUM_ROWS>;

char winner = ' ';

void printBoard(Table const& board) {
	cout << "\n A B C D E F G\n";
	for (int i = 0; i < board.size(); ++i) {
		cout << "|";
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << "|";
		}
		cout << "\n";
	}
	cout << "+-+-+-+-+-+-+-+\n\n";
}

void fillBoard(Table& board, char value) {
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); j++) {
			board[i][j] = value;
		}
	}
}

bool emptySpotsRemain(Table const& board) {
	bool empty = false;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == ' ') {
				empty = true;
			}
		}
	}
	return empty;
}

bool dropPiece(Table& board, int col, char piece) {
    for (int i = board.size() - 1; i >= 0; --i) {
		if (board[i][col] == ' ') {
			board[i][col] = piece;
			return true;
		}
	}
	return false;
}


bool getMove(char turn, int& col) {
	cout << turn << ": ";
	char move;
	do {
		cin >> move;
		move = toupper(move);
	} while (cin && (move < 'A' || move > 'G') && move != 'Q');

	if (!cin || move == 'Q') {
		return false;
	}
	else {
		col = move - 'A';
		return true;
	}
}

bool horizontalWin(Table& board, int row, int col) {
	char piece = board[row][col];
	if (piece == ' ' || col + 3 >= NUM_COLS) return false;
	if (board[row][col + 1] == piece && board[row][col + 2] == piece && board[row][col + 3] == piece) {
		winner = board[row][col];
		for (int i = 0; i < 4; ++i) {
			board[row][col + i] = '*';
		}
		return true;
	}
	return false;
}

bool verticalWin(Table& board, int row, int col) {
	char piece = board[row][col];
	if (piece == ' ' || row + 3 >= NUM_ROWS) return false;
	if (board[row + 1][col] == piece && board[row + 2][col] == piece && board[row + 3][col] == piece) {
		winner = board[row][col];
		for (int i = 0; i < 4; ++i) {
			board[row + i][col] = '*';
		}
		return true;
	}
	return false;
}

bool downDiagonalWin(Table& board, int row, int col) {
	char piece = board[row][col];
	if (piece == ' ' || col + 3 >= NUM_COLS || row + 3 >= NUM_ROWS) return false;
	if (board[row + 1][col + 1] == piece && board[row + 2][col + 2] == piece && board[row + 3][col + 3] == piece) {
		winner = board[row][col];
		for (int i = 0; i < 4; ++i) {
			board[row + i][col + i] = '*';
		}
		return true;
	}
	return false;
}

bool upDiagonalWin(Table& board, int row, int col) {
	char piece = board[row][col];
	if (piece == ' ' || col + 3 >= NUM_COLS || row - 3 < 0) return false;
	if (board[row - 1][col + 1] == piece && board[row - 2][col + 2] == piece && board[row - 3][col + 3] == piece) {
		winner = board[row][col];
		for (int i = 0; i < 4; ++i) {
			board[row - i][col + i] = '*';
		}
		return true;
	}
	return false;
}

char checkForWinner(Table& board) {
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (horizontalWin(board, i, j) ||
				verticalWin(board, i, j) ||
				downDiagonalWin(board, i, j) ||
				upDiagonalWin(board, i, j)) return winner;
		}
	}
	return ' ';
}

int main() {
	Table board;
	fillBoard(board, ' ');
	char turn = 'X', winner = ' ';
	int col;

	printBoard(board);

	while (winner == ' ' && emptySpotsRemain(board) && getMove(turn, col)) {
		dropPiece(board, col, turn);
		printBoard(board);
		if (turn == 'X') {
			turn = 'O';
		}
		else {
			turn = 'X';
		}
		winner = checkForWinner(board);
	}
	if (winner == ' ') {
		cout << "Tie game\n";
	}
	else {
		cout << winner << " wins!\n";
	}
}