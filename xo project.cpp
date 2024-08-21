#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string nameO, nameX;
char order[3][3] = { {'1', '2', '3'}, { '4','5','6' }, { '7','8','9' } };

void Names(string& name1, string& name2) {
    cout << " *** Tic Tac Toe Game ***\n";
    cout << "Enter the name of the first player 'O': ";
    getline(cin, name1);
    cout << "Enter the name of the second player 'X': ";
    getline(cin, name2);
    nameO = name1;
    nameX = name2;
}

bool checkWinner(char player) {
    for (int i = 0; i < 3; ++i)
        if ((order[i][0] == player && order[i][1] == player && order[i][2] == player) || 
            (order[0][i] == player && order[1][i] == player && order[2][i] == player))
            return true;
    return (order[0][0] == player && order[1][1] == player && order[2][2] == player) || 
           (order[0][2] == player && order[1][1] == player && order[2][0] == player);
}

void playerMove(char player) {
    int num;
    bool valid = false;
    string playerName = (player == 'O') ? nameO : nameX;

    while (!valid) {
        cout << "Player " << playerName << ", enter a number: ";
        cin >> num;

        if (cin.fail() || num < 1 || num > 9 || order[(num - 1) / 3][(num - 1) % 3] == 'O' || order[(num - 1) / 3][(num - 1) % 3] == 'X') {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input! Please enter a number from 1 to 9 that hasn't been used yet.\n";
        } else {
            order[(num - 1) / 3][(num - 1) % 3] = player;
            valid = true;
        }
    }
}

void DesignGame() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "   " << order[i][j];
            if (j < 2) cout << " |";
        }
        if (i < 2) cout << "\n--------------------\n";
    }
    cout << "\n";
}

bool checkGrid() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (order[i][j] != 'O' && order[i][j] != 'X')
                return false;
    return true;
}

void resetGame() {
    char start = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            order[i][j] = start++;
}

int main() {
    bool Continue = true;
    while (Continue) {
        system("cls");
        Names(nameO, nameX);
        bool gameOver = false;

        while (!gameOver) {
            system("cls");
            DesignGame();
            playerMove('O');
            if (checkWinner('O')) {
                DesignGame();
                cout << "Player " << nameO << " Wins!\n";
                gameOver = true;
            } else if (checkGrid()) {
                DesignGame();
                cout << "*** It's a Draw! ***\n";
                gameOver = true;
            } else {
                system("cls");
                DesignGame();
                playerMove('X');
                if (checkWinner('X')) {
                    DesignGame();
                    cout << "Player " << nameX << " Wins!\n";
                    gameOver = true;
                } else if (checkGrid()) {
                    DesignGame();
                    cout << "*** It's a Draw! ***\n";
                    gameOver = true;
                }
            }
        }

        cout << "\nDo you want to play another game? (yes/no): ";
        string again;
        cin >> again;
        if (again == "yes" || again == "Yes") {
            resetGame();
            Continue = true;
        } else {
            cout << "******* Game Over *********\n";
            Continue = false;
        }
    }
}
