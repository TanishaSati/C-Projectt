#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x'; // Initial token set to 'x' for the first player
string n1 = "";
string n2 = "";
bool tie = false;

void displayBoard() {
    cout << "     |     |     \n";
    cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
    cout << "     |     |     \n";
}

void functionTwo() {
    int digit;
    if (token == 'x') {
        cout << n1 << ", please enter a number: ";
        cin >> digit;
    } else if (token == '0') {
        cout << n2 << ", please enter a number: ";
        cin >> digit;
    }

    if (digit == 1) {
        row = 0;
        column = 0;
    } else if (digit == 2) {
        row = 0;
        column = 1;
    } else if (digit == 3) {
        row = 0;
        column = 2;
    } else if (digit == 4) {
        row = 1;
        column = 0;
    } else if (digit == 5) {
        row = 1;
        column = 1;
    } else if (digit == 6) {
        row = 1;
        column = 2;
    } else if (digit == 7) {
        row = 2;
        column = 0;
    } else if (digit == 8) {
        row = 2;
        column = 1;
    } else if (digit == 9) {
        row = 2;
        column = 2;
    } else {
        cout << "Invalid input. Please try again.\n";
        functionTwo();
        return;
    }

    if (space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    } else {
        cout << "The cell is already occupied. Please try again.\n";
        functionTwo();
    }

    displayBoard();
}

bool functionthree() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
            return true;
        }
    }

    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    cout << "Enter player 1's name: ";
    getline(cin, n1);
    cout << "Enter player 2's name: ";
    getline(cin, n2);
    cout << n1 << " is player 1, so they will play first.\n";
    cout << n2 << " is player 2, so they will play second.\n";

    while (!functionthree()) {
        displayBoard();
        functionTwo();
    }

    if (tie) {
        cout << "It's a tie between " << n1 << " and " << n2 << "!\n";
    } else {
        if (token == '0') { // The token was switched after the last valid move
            cout << n1 << " wins!!\n";
        } else {
            cout << n2 << " wins!!\n";
        }
    }

    return 0;
}
