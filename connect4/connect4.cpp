#ifndef TESTS
#include <iostream>
#include "connect4_function.h"

using namespace std;

int main(){
	game_board* gameboard = new game_board(9, 6);
	players* a = new computer_player('A', gameboard);
	players* b = new computer_player('B', gameboard);
	int column = 0;
	bool winA = false, winB = false;
	bool full = gameboard->is_full();

	while (!winA && !winB && !full) {
		column = a->throw_coin();
		gameboard->put_coin(column, 'A');

		winA = gameboard->win('A');
		full = gameboard->is_full();

		if (!full && !winA){
			column = b->throw_coin();
			gameboard->put_coin(column, 'B');

			winB = gameboard->win('B');
			full = gameboard->is_full();
		}
		gameboard->print_board();
		cout << endl;
	}
	
	gameboard->win('A')? cout << "A won. ": cout<< "A did not win. ";
	gameboard->win('B')? cout << "B won. ": cout << "B did not win. ";

	return 0;
}
#endif // !TESTS
