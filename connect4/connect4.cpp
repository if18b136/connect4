#include "connect4_function.h"
#include <iostream>

using namespace std;

#ifndef TESTS
int main(){
	game_board* gameboard = new game_board(9, 6);
	bool win = false;

	gameboard->put_coin(1, 'A');

	gameboard->put_coin(2, 'B');
	gameboard->put_coin(2, 'A');

	gameboard->put_coin(3, 'B');
	gameboard->put_coin(3, 'B');
	gameboard->put_coin(3, 'A');

	gameboard->put_coin(4, 'B');
	gameboard->put_coin(4, 'B');
	gameboard->put_coin(4, 'B');
	gameboard->put_coin(4, 'A');

	gameboard->print_board();
	
	return 0;
}
#endif // !TESTS
