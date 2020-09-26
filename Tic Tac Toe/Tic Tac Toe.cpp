#include <iostream>
#include <string>
#include <vector>

//table for the Game field

char table[9] = {	'1','2','3',
					'4','5','6',
					'7','8','9' };

void board();
int winconditions(); 

int main() 
{
	char XO; 
	int choice{0}; // Where you choose to put X or O
	int player = 1; 

		do
		{
			choice = 0;
			system("cls"); // clears the console
			player = (player % 2) ? 1 : 2; // returs player 1 or 2
			XO = (player == 1) ? 'X' : 'O'; // returns X or O depending on whos turn it is

			board();
			std::cout << "Player " << player << " Choose a number to put " << XO << "\n";
			std::cin >> choice;
		
			if (table[choice - 1] != 'X' && table[choice - 1] != 'O' && choice < 10) //if not X or O in table then put X or O else invalid move
			{
				table[choice - 1] = XO;
				player++;
			}
			else
			{
				std::cout << "Invalid move\n";
				system("pause");
			}

		} while (winconditions() == 2);

	system("cls");
	board();
	if (winconditions() == 1)
		std::cout << "Player " << --player << " win!\n\n";
	else {
		std::cout << "Game drawn\n\n";
	return 0;
	}
}

// returns: 1 = game won / 2 = game in progress / 0 = game drawn
	int winconditions()
	{
		if (table[0] == table[1] && table[1] == table[2])
			return 1;

		else if (table[3] == table[4] && table[4] == table[5])
			return 1;

		else if (table[6] == table[7] && table[7] == table[8])
			return 1;

		else if (table[0] == table[3] && table[3] == table[6])
			return 1;

		else if (table[1] == table[4] && table[4] == table[7])
			return 1;

		else if (table[2] == table[5] && table[5] == table[8])
			return 1;

		else if (table[0] == table[4] && table[4] == table[8])
			return 1;

		else if (table[2] == table[4] && table[4] == table[6])
			return 1;

		else if (table[0] != '1' && table[1] != '2' && table[2] != '3'
			&& table[3] != '4' && table[4] != '5' && table[5] != '6'
			&& table[6] != '7' && table[7] != '8' && table[8] != '9')
			return 0;

		else
			return 2;
	}

	//simple game board
void board()
{
	std::cout << "\t--TIC TAC TOE--\n";
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) {
			std::cout << "\n\n";
		} // if index devisable by 3 end line
		std::cout << "\t" << table[i] << " ";
	}
	std::cout << "\n\n\n";
}