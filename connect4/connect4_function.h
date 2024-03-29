#ifndef _CONNECT4_HEADER_
#define _CONNECT4_HEADER_

using namespace std;

class game_board {
public:
	game_board(int width, int height); //Constructor
	~game_board(); //Destructor
	bool is_full();
	bool col_full(int column);
	bool put_coin(int column, char player);
	bool check_field(int width, int height, char player);
	bool win_vertical(char player);
	bool win_horizontal(char player);
	bool win_diagonal(char player);
	bool win(char player);
	void print_board();
	char** getField();

#ifdef TESTS
public:
#else
private:
#endif
	int width;
	int height;
	char** field;
};

//Interface
class players {
public:
	//virtual ~players(); //Destructor
	virtual int throw_coin() = 0;
	virtual const char& getmName() const = 0;
};

class human_player : public players {
public:
	human_player(const char &name); //Constructor
	~human_player(); //Destructor
	int throw_coin();
	const char& getmName() const; //Getter to read Name of Human Player

#ifdef TESTS
public:
#else
private:
#endif
	char mName;
};

class computer_player : public players {
public:
	//computer_player(const char &name, game_board* spielfeld); //Constructor
	//~computer_player(); //Destructor
	//int throw_coin();
	//const char& getmName() const; //Getter to read Name of Computer Player

#ifdef TESTS
public:
#else
private:
#endif
	char mName;
	game_board* gameboard;
};

#endif