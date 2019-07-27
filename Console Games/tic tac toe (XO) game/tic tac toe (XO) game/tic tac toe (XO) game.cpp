/// Youssef Mohamed 
/// faculty of science - Alexandria University

// https://github.com/YoussefMo7amed
// https://codeforces.com/profile/YoussefMo7amed
// just for practcing and learning  :D 

// simple console  game
/* ( TIC TAC TOE ) Game  V1 */

#include <iostream>
#include <cwchar>
#include <windows.h>

using namespace std;

// handling non-int
// the board

char board[3][3];
char player; // X or O 
int counter = 0; // it countes number of playing 

static int played_matches = 0;	// total matches
static int X_PLayer = 0;		// Number of wins of X 
static int O_Player = 0;		// Number of wins of O 
static int drawing = 0;			// number of Drawing

// initialize the board from 1 to 9 
// *the default player (first player) is alwayes (X) player 
void initialization()
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			k++;
			board[i][j] = char(k + 48);
		}
	}
	player = 'X';
	counter = 0;
}

int check()
{
	int a;
	cin >> a;

	while (!cin.good())
	{
		cout << "\n*ERROR: PLEASE ENTER CORRECT NUMBER (1 - 9)\n";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> a;
	}

	return a;
}

void screen()
{
	// Screen 
	system("cls"); // clear the last screen (update the screen) 
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 3;
	cfi.dwFontSize.X = 20;                   // Width of each character in the font
	cfi.dwFontSize.Y = 48;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	
	// if you want to change the font 
	//	std::wcscpy (cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	// showing
	cout << "\t\t\t   tic tac toe (XO)" << endl;
	//cout << "\t\t\t ====================" << endl;
	//cout << "\t\t\t ..................." << endl;
	cout << "\t\t\t -------------------" << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "\t\t\t        ";
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	//cout << "\t\t\t ====================" << endl;
	//cout << "\t\t\t ..................." << endl;
	cout << "\t\t\t -------------------" << endl;
}

int input()
{
	int a;
	cout << "\n(" << player << ") Turn!\nPress the number of the cell: ";
	
	a = check(); // handling non-int
	
	if (a >= 1 && a <= 9)
	{
		// check if the 'a' cell is valid or not 
		if (a == 1)
		{
			// if the cell = its position, so it is valid (empty)
			// else, it means it not valid (not empty)
			if (board[0][0] == '1')
			{
				board[0][0] = player;
				return 1;
			}
			return 0;
		}
		else if (a == 2)
		{
			if (board[0][1] == '2')
			{
				board[0][1] = player;
				return 1;
			}
			return 0;
		}
		else if (a == 3)
		{
			if (board[0][2] == '3')
			{
				board[0][2] = player;
				return 1;
			}
			return 0;
		}
		else if (a == 4)
		{
			if (board[1][0] == '4')
			{
				board[1][0] = player;
				return 1;
			}
			return 0;
		}
		else if (a == 5)
		{
			if (board[1][1] == '5')
			{
				board[1][1] = player;
				return 1;
			}
			return 0;
		}
		else if (a == 6)
		{
			if (board[1][2] == '6')
			{
				board[1][2] = player;
				return 1;
			}
			return 0;
		}
		else if (a == 7)
		{
			if (board[2][0] == '7')
			{
				board[2][0] = player;
				return 1;
			}
			return 0;
		}
		else if (a == 8)
		{
			if (board[2][1] == '8')
			{
				board[2][1] = player;
				return 1;
			}
			return 0;
		}
		else if (a == 9)
		{
			if (board[2][2] == '9')
			{
				board[2][2] = player;
				return 1;
			}
			return 0;
		}
	}
	else
	{
		cout << "\n*PLEASE ENTER VALID NUMBER (CELL)\n";
		input();
	}
}

//toggle Player function (X or O)
void togglePlayer()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

// whose win
char win()
{
	///first player
	
	//Rows
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		return 'X';
	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		return 'X';
	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		return 'X';

	//Columes
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		return 'X';
	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		return 'X';
	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		return 'X';

	//Digonal
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		return 'X';
	if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
		return 'X';

	///second player
	
	//Rows
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		return 'O';
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		return 'O';
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		return 'O';
	
	//Columes
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
		return 'O';
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		return 'O';
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		return 'O';
	
	//Digonal
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		return 'O';
	if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
		return 'O';

	return '/';
}

void message()
{
	cout << "PRESS:\n(1-9)\tto play another match\n(0)\tto exit\n";
}

void details()
{
	cout << "DETAILS:\n  ";
	cout << played_matches << " played";
	if (played_matches == 1)
		cout << " match\n";
	else
		cout << " matches\n";
	cout << "\tPlayer X won:\t\t" << X_PLayer << " times" ;
	cout << endl;
	cout << "\tPlayer O won:\t\t" << O_Player << " times";
	cout << endl;
	cout << "\tDraw:\t\t\t" << drawing << " times" << endl;
	message();
}

void result()
{
	cout << "\t\t\t     ";
	if (win() == 'X')
	{
		cout << "- X wins! -" << endl;
		X_PLayer++;
	}
	else if (win() == 'O')
	{
		cout << "- O wins! -" << endl;
		O_Player++;
	}
	else if (counter == 9)
	{
		cout << "  - DRAW! -" << endl;
		drawing++;
	}
	cout << "\t\t\t -------------------" << endl;
}

void finalResult()
{
	system("CLS");
	string  c = "";

	bool B = true;
	if (X_PLayer > O_Player)
	{
		c = "(X)";
	}
	else if (O_Player > O_Player)
	{
		c = "(O)";
	}
	else
	{
		c = "    NO ONE!\n";
		B = false;
	}
	cout << "THE FINAL WINNER IS:\n";
	cout << "\t\t\t ---------------------" << endl;
	cout << "\t\t\t      " << c;
	if (B)
		cout << " PLAYER!" << endl;
	cout << "\t\t\t ---------------------" << endl;

}

int main()
{
	initialization();
	screen();
	
	bool a = true;

	while (a)
	{
		int valid;
		valid = input();
		if (valid == 1)
		{
			counter++;
		}
		if (!valid)
		{
			cout << "ERROR: NOT VALID CELL!!, USE VALID ONE\n";
			continue;
		}
		else
		{
			screen();
			if (win() == 'X' || win() == 'O' || counter == 9)
			{
				played_matches++;
				
				result();

				details();

				int i;
				i = check();
				if (!i)
				{
					finalResult();
					break;
				}
				else
				{
					initialization();
					valid = 1;
					screen();
					continue;
				}
			}
			togglePlayer();
		}
	}
	
	cout << "GOODBYE!\n";

	system("pause");
	return 0;
}
