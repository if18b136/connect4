#include "connect4_function.h"
#include <iostream>

using namespace std;

game_board::game_board(int width, int height){
	this->width = width;
	this->height = height;
	this->field = new char*[width];
	for (int col = 0; col < width; ++col) {
		this->field[col] = new char[height];
		for (int row = 0; row < height; row++) {
			this->field[col][row] = '.';
		}
	}
}

game_board::~game_board(){
	for (int col = 0; col < width; col++) {
		delete[] this->field[col];
	}
	delete[] this->field;
}

bool game_board::col_full(int column){
	if (this->field[column][0] == '.') {
		return false;
	}
	else {
		return true;
	}
}

bool game_board::is_full(){
	bool full = true;
	for (int col = 0; col < this->width; col++) {
		full = col_full(col);
		if (!full) {
			return full;
		}
	}
	return full;
}

bool game_board::put_coin(int column, char player){
	if (col_full(column-1)) {
		return false;
	}
	else {
		int curr_height = this->height-1;
		while (this->field[column-1][curr_height] != '.') {
			curr_height--;
		}
		this->field[column-1][curr_height] = player;
		return true;
	}
}

bool game_board::check_field(int width, int height, char player) {
	if (this->field[width][height] == player) {
		return true;
	}
	else {
		return false;
	}
}

bool game_board::win_vertical(char player) {
	for (int height_limit = this->height - 1; height_limit > 2; height_limit--) {
		for (int col = 0; col < this->width; col++) {
			bool win = true;
			int four = 1 + (this->height-1-height_limit);  //consider winning from a row above
			while (win && four != 5 + (this->height - 1 - height_limit)) {
				win = check_field(col, this->height - four, player);
				four++;
			}
			if (win) { return win; }
		}
	}
	return false;
}

bool game_board::win_horizontal(char player) {
	for (int row = this->height - 1; row >= 0; row--) {
		for (int col = 0; col < this->width - 3; col++) {
			bool win = true;
			int four = 0;
			while (win && four != 4) {
				win = check_field(col + four, row, player);
				four++;
			}
			if (win) { return win; }
		}
	}
	return false;
}

bool game_board::win_diagonal(char player) {
	for (int row = this->height - 1; row >= 3; row--) {
		for (int col = 0; col < this->width - 3; col++) {
			bool win = true;
			int four = 0;
			while (win && four != 4) {
				win = check_field(col + four, row - four, player);
				four++;
			}
			if (win) { return win; }
		}
	}
	for (int row = 0; row < this->height - 3; row++) {
		for (int col = 0; col < this->width - 3; col++) {
			bool win = true;
			int four = 0;
			while (win && four != 4) {
				win = check_field(col + four, row + four, player);
				four++;
			}
			if (win) { return win; }
		}
	}
	return false;
}

bool game_board::win(char player){
	if (win_vertical(player)) {
		return win_vertical(player);
	}
	if(win_horizontal(player)) {
		return win_horizontal(player);
	}
	if (win_diagonal(player)) {
		return win_diagonal(player);
	}
	return false;
}

void game_board::print_board() {
	int column = 1;
	for (int row = 0; row < this->height; row++) {
		for (int col = 0; col < this->width; col++) {
			cout << this->field[col][row];
		}
		cout << column++ << endl;
	}
	for (int col = 1; col <= this->width; col++) {
		cout << col;
	}
}

char** game_board::getField(){
	return this->field;
}

human_player::human_player(const char &name){
	this->mName = name;
}

human_player::~human_player(){
	this->mName = 0;
}

int human_player::throw_coin() {
	int column = 0;
	cout << "Enter column in which you want to throw your coin: ";
	cin >> column;
	return column;
}

const char& human_player::getmName() const {
	return this->mName;
}