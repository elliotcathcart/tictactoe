// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Date started: 2020/02/01
// Description: Tic tac toe game project
//
// todo: implement AI
// todo: implement menu system (choice between 1 / 2 player, show leaderboard etc)
// todo: fix bug - enter letter at player turn causes infinite print loop
// todo: refactor

using namespace std;
#include <iostream>
#include <string>

// Function prototypes
void printBoard(char* boardPtr);
bool checkWin(char* boardPtr, char letter);
void startGame(int &p1WinCount, int &p2WinCount);
void playerTurn(int playerNumber, char* boardPtr);

int main() {
	int p1WinCount = 0, p2WinCount = 0;
	cout << "Welcome to Tic Tac Toe!\nWould you like to play a game? (Y/N) ";

	string entry;
	getline(cin, entry);
	char play = entry[0];
	while (toupper(play) != 'N') {
		if (toupper(play) == 'Y') {
			cout << "\nLet's get started, have fun!" << endl;
			startGame(p1WinCount, p2WinCount);
			cout << "\nLeaderboard: \nPlayer 1: " << p1WinCount << " win(s) \nPlayer 2: " << p2WinCount << " win(s)\n\n";
			cout << "Would you like to play again? Y/N ";
		}
		else {
			cout << "Not a valid entry, Y or N only, try again! \nWould you like to play a game? Y/N ";
		}
		getline(cin, entry);
		play = entry[0];
	}
	cout << "Thanks for playing!" << endl;

}

void printBoard(char *boardPtr) {
	cout << "\n";
	for (int i = 1; i < 10; i++) {
		cout << " " << *(boardPtr + i) << " ";
		if (i == 3 || i == 6) {
			cout << "\n --+----+--\n";
		}
		else if (i == 9) {
			cout << "\n\n";
		}
		else {
			cout << "| ";
		}
	}
}

bool checkWin(char* boardPtr, char letter) {
	// horizontal win conditions
	if (*(boardPtr + 1) == letter && *(boardPtr + 2) == letter && *(boardPtr + 3) == letter) {
		return true;
	}
	if (*(boardPtr + 4) == letter && *(boardPtr + 5) == letter && *(boardPtr + 6) == letter) {
		return true;
	}
	if (*(boardPtr + 7) == letter && *(boardPtr + 8) == letter && *(boardPtr + 9) == letter) {
		return true;
	}
	// diagonal win conditions
	if (*(boardPtr + 1) == letter && *(boardPtr + 5) == letter && *(boardPtr + 9) == letter) {
		return true;
	}
	if (*(boardPtr + 3) == letter && *(boardPtr + 5) == letter && *(boardPtr + 7) == letter) {
		return true;
	}
	// vertical win conditions
	if (*(boardPtr + 1) == letter && *(boardPtr + 4) == letter && *(boardPtr + 7) == letter) {
		return true;
	}
	if (*(boardPtr + 2) == letter && *(boardPtr + 5) == letter && *(boardPtr + 8) == letter) {
		return true;
	}
	if (*(boardPtr + 3) == letter && *(boardPtr + 6) == letter && *(boardPtr + 9) == letter) {
		return true;
	}
	return false;
}

void playerTurn(int playerNumber, char* boardPtr) {
	char letter;
	if (playerNumber == 1) {
		letter = 'X';
	}
	else {
		letter = 'O';
	}

	cout << "Player " << playerNumber << ", enter position of " << letter << ": ";

	int position;
	cin >> position;	
	while (!(position > 0 && position < 10)) {
		cout << "That position is invalid, please try again: ";
		cin >> position;
	}
	while (true) {
		if (*(boardPtr + position) != 'X' && *(boardPtr + position) != 'O') {
			*(boardPtr + position) = letter;
			printBoard(boardPtr);
			break;
		}
		else {
			cout << "That position is already taken, please try again: ";
			cin >> position;
		}
	}
}

void startGame(int &p1WinCount, int &p2WinCount) {
	// create and populate new board
	char board[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char* boardPtr = &board[0];
	printBoard(board);

	// iterates through max possible moves (9), unless someone wins first
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 0) {
			playerTurn(2, boardPtr);
			if (checkWin(boardPtr, 'O')) {
				cout << "Player 2 wins! " << endl;
				p2WinCount++;
				break;
			}
		}
		else {
			playerTurn(1, boardPtr);
			if (checkWin(boardPtr, 'X')) {
				cout << "Player 1 wins! " << endl;
				p1WinCount++;
				break;
			}
		}
		if (i == 9) {
			cout << "It's a draw! You both lose! \n\n";
		}
	}
}
