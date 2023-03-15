#include <iostream>

struct position{
	int x; int y;
};

void display_rules(){
	std::cout << "RULES: " << std::endl;
	std::cout << "To make a move player shoud write a coordinate of the field, " << std::endl;
	std::cout << "where he wants to put his symbol. The reference point is the " << std::endl;
	std::cout << "upper left corner. Example: " << std::endl;
	std::cout << "Player's 1 move: 1 2" << std::endl;
	std::cout << "   |   |   " << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << "   |   | X " << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << "   |   |   " << std::endl;
}

template<size_t n>
void display_board(char (&board)[n][n]){
	std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << std::endl;
}

template<size_t n>
void change_board(char (&board)[n][n], position pos, char symbol){
	board[pos.x][pos.y] = symbol;
}

template<size_t n>
bool position_check(char (&board)[n][n], position pos){
	if(pos.x < 0 || pos.x > 2 || pos.y < 0 || pos.y > 2 )
		return true;
	if (board[pos.x][pos.y] == ' ')
		return false;
	else
		return true;
}

template<size_t n>
bool win_check(char (&board)[n][n], char symbol){
	if(board[0][0] == board[0][1] && board[0][1] ==  board[0][2] && board[0][2] == symbol)
		return true;
	else if(board[2][0] == board[1][1] && board[1][1] ==  board[1][2] && board[1][2] == symbol)
		return true;
	else if(board[2][0] == board[2][1] && board[2][1] ==  board[2][2] && board[2][2] == symbol)
		return true;
	else if(board[0][0] == board[1][0] && board[1][0] ==  board[2][0] && board[2][0] == symbol)
		return true;
	else if(board[0][1] == board[1][1] && board[1][1] ==  board[2][1] && board[2][1] == symbol)
		return true;
	else if(board[0][2] == board[1][2] && board[1][2] ==  board[2][2] && board[2][2] == symbol)
		return true;
	else if(board[0][0] == board[1][1] && board[1][1] ==  board[2][2] && board[2][2] == symbol)
		return true;
	else if(board[0][2] == board[1][1] && board[1][1] ==  board[2][0] && board[2][0] == symbol)
		return true;
	else return false;
}

int main(){
	const size_t N = 3;
	char board[N][N];
	int counter = 0;
	position pos;

	//board initialization
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			board[i][j] = ' ';
		}
	}
	
	display_rules();
	std::cout << "To start game write 1: ";
	int flag = 0;
	while(flag != 1)
		std::cin >> flag; 

	//game starts
	display_board(board);	
	while(true){
		if(counter % 2 == 0){
			std::cout << "Player's 1 move: ";
			std::cin >> pos.x >> pos.y;
			while(position_check(board, pos)){
				std::cout << "Wrong move!" << std::endl;
				std::cout << "Player's 1 move: ";
				std::cin >> pos.x >> pos.y;
			}
			change_board(board, pos, 'X');
		}
		else{
			std::cout << "Player's 2 move: ";
			std::cin >> pos.x >> pos.y;
			while(position_check(board, pos)){
				std::cout << "Wrong move!" << std::endl;
				std::cout << "Player's 2 move: ";
				std::cin >> pos.x >> pos.y;
			}
			change_board(board, pos, '0');
		}
		display_board(board);

		//check if game need to end
		if(win_check(board, 'X')){
			std::cout << "Player 1 won!" << std::endl;
			break;
		}
		else if (win_check(board, '0')){
			std::cout << "Player 2 won!" << std::endl;
			break;
		}
		if(counter >= 8){
			std::cout << "Draw!" << std::endl;
			break;
		}
		counter++;
	}
	return 0;
}
