#include <iostream>
#include <string>
#include <iomanip>
#include<cstdlib>
using namespace std;
bool win = true;
string nameO, nameX;
char order[3][3] = { {'1', '2', '3'}, { '4','5','6' }, { '7','8','9' } };
// Entering players name
void Names(string& name1, string& name2)
{
	cout << " *** Tic Tac Toe Game ***\n";
	cout << "Enter the name of the first player \'O\' player \n";
	getline(cin, name1);
	cout << "Enter the name of the second player \'X\' player \n";
	getline(cin, name2);
	nameO = name1;
	nameX = name2;
}
//check if winner o is win or not
bool winnerO()
{

	if (order[0][0] == 'O' && order[0][1] == 'O' && order[0][2] == 'O' ||
		order[0][0] == 'O' && order[1][0] == 'O' && order[2][0] == 'O' ||
		order[1][0] == 'O' && order[1][1] == 'O' && order[1][2] == 'O' ||
		order[2][0] == 'O' && order[2][1] == 'O' && order[2][2] == 'O' ||
		order[0][1] == 'O' && order[1][1] == 'O' && order[2][1] == 'O' ||
		order[0][2] == 'O' && order[1][2] == 'O' && order[2][2] == 'O' ||
		order[0][0] == 'O' && order[1][1] == 'O' && order[2][2] == 'O' ||
		order[0][2] == 'O' && order[1][1] == 'O' && order[2][0] == 'O')
		return true;
	else
		return false;
}
//check if winner x is win or not
bool winnerX()
{
	if (order[0][0] == 'X' && order[0][1] == 'X' && order[0][2] == 'X' ||
		order[0][0] == 'X' && order[1][0] == 'X' && order[2][0] == 'X' ||
		order[1][0] == 'X' && order[1][1] == 'X' && order[1][2] == 'X' ||
		order[2][0] == 'X' && order[2][1] == 'X' && order[2][2] == 'X' ||
		order[0][1] == 'X' && order[1][1] == 'X' && order[2][1] == 'X' ||
		order[0][2] == 'X' && order[1][2] == 'X' && order[2][2] == 'X' ||
		order[0][0] == 'X' && order[1][1] == 'X' && order[2][2] == 'X' ||
		order[0][2] == 'X' && order[1][1] == 'X' && order[2][0] == 'X')
		return true;
	else
		return false;
}
/*	Enter position of player O 
	check if this position is empty or not
	if it is empty Store O in this position 
	otherwise re_enter new position to check again*/
void playerO()
{
	int num;
	bool valid = false;
	cout << "Player " << nameO << " enter a number \n";
	cin >> num;
	while (!valid) {
		if (num >= 1 && num <= 9 && order[(num - 1) / 3][(num - 1) % 3] != 'O' && order[(num - 1) / 3][(num - 1) % 3] != 'X')
		{
			switch (num)
			{
			case 1:order[0][0] = 'O'; break;
			case 2:order[0][1] = 'O'; break;
			case 3:order[0][2] = 'O'; break;
			case 4:order[1][0] = 'O'; break;
			case 5:order[1][1] = 'O'; break;
			case 6:order[1][2] = 'O'; break;
			case 7:order[2][0] = 'O'; break;
			case 8:order[2][1] = 'O'; break;
			case 9:order[2][2] = 'O'; break;

			}
			valid = true;
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			valid = false;
			cout << "Invalid value please enter a number from 1 to 9 hasn't been used yet \n";
			cin >> num;
		}
		else
		{
			valid = false;
			cout << "Invalid value please enter a number from 1 to 9 hasn't been used yet \n";
			cin >> num;
		}
	}
}
/*	Enter position of player X
	check if this position is empty or not
	if it is empty Store X in this position
	otherwise re_enter new position to check again*/
void playerX()
{
	int num;
	bool valid = false;
	cout << "Player " << nameX << " enter a number \n ";
	cin >> num;
	while (!valid)
	{
		if (num >= 1 && num <= 9 && order[(num - 1) / 3][(num - 1) % 3] != 'O' && order[(num - 1) / 3][(num - 1) % 3] != 'X')
		{
			switch (num)
			{
			case 1:order[0][0] = 'X'; break;
			case 2:order[0][1] = 'X'; break;
			case 3:order[0][2] = 'X'; break;
			case 4:order[1][0] = 'X'; break;
			case 5:order[1][1] = 'X'; break;
			case 6:order[1][2] = 'X'; break;
			case 7:order[2][0] = 'X'; break;
			case 8:order[2][1] = 'X'; break;
			case 9:order[2][2] = 'X'; break;
			}
			valid = true;
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			valid = false;
			cout << "Invalid value please enter a number from 1 to 9 hasn't been used yet \n";
			cin >> num;
		}
		else
		{
			valid = false;
			cout << "Invalid value please enter a number from 1 to 9 hasn't been used yet \n";
			cin >> num;
		}
	}
}
// Designing what will user see (User Interface)
void DesignGame()
{

	cout << "   " << order[0][0] << setw(3) << "|" << "   " << order[0][1] << setw(3) << "|" << "   " << order[0][2] << setw(3) << "\n";
	cout << "--------------------\n";
	cout << "   " << order[1][0] << setw(3) << "|" << "   " << order[1][1] << setw(3) << "|" << "   " << order[1][2] << setw(3) << "\n";
	cout << "--------------------\n";
	cout << "   " << order[2][0] << setw(3) << "|" << "   " << order[2][1] << setw(3) << "|" << "   " << order[2][2] << setw(3) << "\n";
}

// Checking if there is still any empty position in grid to continue game or not
bool checkGrid()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (order[i][j] != 'O' && order[i][j] != 'X')
				return false;
		}
	}
	return true;
}

int main()
{
	system("cls");
	bool Continue = true;
	while (Continue)
	{
		Names(nameO, nameX);
		while (!winnerO() && !winnerX())
		{
			DesignGame();
			playerO();

			if (winnerO())
			{
				DesignGame();
				cout << "Player " << nameO << " Wins" << "\n";
				cout << "**** Winner Winner Chicken Dinner ****";
				break;
			}
			if (checkGrid())
			{
				DesignGame();
				cout << "*** It's a Draw !!!!!\n";
				break;
			}

			system("cls");
			DesignGame();
			playerX();
			if (winnerX())
			{
				DesignGame();
				cout << "Player " << nameX << " Wins" << "\n";
				cout << "**** Winner Winner Chicken Dinner ****";
				break;
			}

			if (checkGrid())
			{
				DesignGame();
				cout << "**** It's a Draw !!!!!\n";
				break;
			}

			system("cls");

		}
		cout << "\nDo You want to play anther Game or not ??\n";
		cout << "Enter Yes to play or No to End\n";
		string again;
		cin >> again;
		if (again == "yes" || again == "Yes")
		{
			system("cls");
			order[0][0] = '1';
			order[0][1] = '2';
			order[0][2] = '3';
			order[1][0] = '4';
			order[1][1] = '5';
			order[1][2] = '6';
			order[2][0] = '7';
			order[2][1] = '8';
			order[2][2] = '9';
			winnerO();
			winnerX();
			Continue = true;
		}
		else {
			cout << "******* GameOver *********\n";
			Continue = false;
		}

	}
}