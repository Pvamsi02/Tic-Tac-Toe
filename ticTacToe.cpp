#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
vector<vector<char>> game(3, vector<char>(3));
int winner = 0;
bool positions[9];
void displayGame(void);
void showChoice(void);
void getPos(int i, int &j, int &k);
bool validate(int i);
void PvsP(void);
void PvsC(void);
char checkWinner(void);
bool getPlayerMove(char c);
bool getMyMove(char c);
int main()
{
input:
	cout << "Welcome to Tic Tac to game" << endl;
	cout << "Choice 1:Player vs Player\nChoice 2:Player vs Computer\n";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			game[i][j] = ' ';
		}
	int choice, option;
	cin >> choice;
	switch (choice)
	{
	case 1:
		PvsP();
		break;
	case 2:
		PvsC();
		break;

	default:
		cout << "Wrong Call try again!\n"
			 << endl;
		goto input;
		break;
	}
	cout << "Thank you Bye!";
	return 0;
}
bool validate(int i)
{
	if (i >= 0 && i < 9)
		return true;
	return false;
}
bool getPlayerMove(char c)
{
	int p1, pos1, pos2;
	cin >> p1;
	if (validate(p1) == false || positions[p1] == true)
	{
		cout << "invalid try again!\n";
		getPlayerMove(c);
	}
	else
	{
		getPos(p1, pos1, pos2);
		game[pos1][pos2] = c;
		positions[p1] = true;
		winner++;
	}
	if (winner >= 9)
	{
		cout << "Draw" << endl;
		displayGame();
		return true;
	}
	return false;
}
bool getMyMove(char c)
{
	int p1, pos1, pos2;
	p1 = rand() % 8;
	if (positions[p1] == true)
	{
		getMyMove(c);
	}
	else
	{
		cout << p1 << endl;
		getPos(p1, pos1, pos2);
		game[pos1][pos2] = c;
		positions[p1] = true;
		winner++;
	}
	if (winner >= 9)
	{
		cout << "Draw" << endl;
		displayGame();
		return true;
	}
	return false;
}
char checkWinner(void)
{
	for (int i = 0; i < 3; i++)
		if ((game[i][0] == game[i][1]) && (game[i][0] == game[i][2]) && (game[i][0] == 'X' || game[i][0] == 'O'))
		{
			cout << "Line in Row " << i << endl;
			return game[i][0];
		}
	for (int i = 0; i < 3; i++)
		if ((game[0][i] == game[1][i]) && (game[0][i] == game[2][i]) && (game[0][i] == 'X' || game[0][i] == 'O'))
		{
			cout << "Line in Column " << i << endl;
			return game[0][i];
		}
	if ((game[0][0] == game[1][1]) && (game[0][0] == game[2][2]) && (game[0][0] == 'X' || game[0][0] == 'O'))
	{
		cout << "Line in Diagonal " << endl;
		return game[0][0];
	}
	if ((game[0][2] == game[1][1]) && (game[0][2] == game[2][0]) && (game[0][2] == 'X' || game[0][2] == 'O'))
	{
		cout << "Line in Diagonal " << endl;
		return game[0][0];
	}
	return ' ';
}
void displayGame(void)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "----------------\n";
		cout << "|    |    |    |\n";
		cout << "| " << game[i][0] << "  | " << game[i][1] << "  | " << game[i][2] << "  |\n";
		cout << "|    |    |    |\n";
	}
	cout << "----------------\n";
}
void showChoice(void)
{
	int a = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "------------------\n";
		cout << "  |    |    |    |\n";
		for (int j = 0; j < 3; j++)
		{
			cout << "  | " << i + j + a;
			// game[i][j] = i + j + a;
		}
		a++;
		a++;
		cout << "  |\n  |    |    |    |\n";
	}
	cout << "------------------\n";
}
void getPos(int i, int &j, int &k)
{
	switch (i)
	{
	case 0:
		j = 0;
		k = 0;
		break;
	case 1:
		j = 0;
		k = 1;
		break;
	case 2:
		j = 0;
		k = 2;
		break;
	case 3:
		j = 1;
		k = 0;
		break;
	case 4:
		j = 1;
		k = 1;
		break;
	case 5:
		j = 1;
		k = 2;
		break;
	case 6:
		j = 2;
		k = 0;
		break;
	case 7:
		j = 2;
		k = 1;
		break;
	case 8:
		j = 2;
		k = 2;
		break;
	default:
		break;
	}
}
void PvsP(void)
{
	cout << "-------------------- Now you are going to play against among Yourself!--------------------" << endl;
	cout << "Player1 (X) vs Player2 (O)\n";
	char done = ' ';
	showChoice();
	while (done == ' ')
	{
		cout << "Player1 Choice:";
		if (getPlayerMove('X'))
			break;

		done = checkWinner();
		if (done == 'X')
		{
			cout << "------------------------------> Player 1 is winner\n";
			displayGame();
			break;
		}

		cout << "Player2 Choice:";
		if (getPlayerMove('O'))
			break;

		done = checkWinner();
		if (done == 'O')
		{
			cout << "------------------------------> Player 2 is winner\n";
			displayGame();
			break;
		}
		// cout << done << endl;
		displayGame();
		// if (flag)
		//     break;
	}
}
void PvsC(void)
{
	cout << "-------------------- Now you are going to play against me!--------------------" << endl;
	cout << "Options:\n1.Player (X) vs Computer (O)\n2.Computer (X) vs Player (O)\n";
	srand(time(0));
	int options = rand() % 2;
	if (options == 1)
	{
		cout << "Computer (X) vs Player (O)\n";
		char done = ' ';
		showChoice();
		while (done == ' ')
		{
			cout << "My Choice:";
			if (getMyMove('X'))
				break;

			done = checkWinner();
			if (done == 'X')
			{
				cout << "------------------------------> Computer is winner\n";
				displayGame();
				break;
			}

			cout << "Player Choice:";
			if (getPlayerMove('O'))
				break;

			done = checkWinner();
			if (done == 'O')
			{
				cout << "------------------------------> Player is winner\n";
				displayGame();
				break;
			}
			// cout << done << endl;
			displayGame();
		}
	}
	else
	{
		cout << "Player (X) vs Computer (O)\n";
		char done = ' ';
		showChoice();
		while (done == ' ')
		{
			cout << "Player Choice:";
			if (getPlayerMove('X'))
				break;

			done = checkWinner();
			if (done == 'X')
			{
				cout << "------------------------------> Player is winner\n";
				displayGame();
				break;
			}

			cout << "My Choice:";
			if (getMyMove('O'))
				break;

			done = checkWinner();
			if (done == 'O')
			{
				cout << "------------------------------> Player 2 is winner\n";
				displayGame();
				break;
			}
			// cout << done << endl;
			displayGame();
		}
	}
	// displayGame();
}
