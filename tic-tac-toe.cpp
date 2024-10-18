#include <iostream>
char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

bool GameRun = true;

void DrawBoard() {
    std::cout << ' ' << board[0] << " | " << board[1] << " | " << board[2] << ' ' << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << ' ' << board[3] << " | " << board[4] << " | " << board[5] << ' ' << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << ' ' << board[6] << " | " << board[7] << " | " << board[8] << ' ' << std::endl;
}

char move(char Char) {
    char in_char;
    std::cout << "Player " << Char << " Enter the position between [0-8]: ";
    std::cin >> in_char;
    int movement = in_char - '0';
    if (movement<=8 && movement>=0) {
        if (board[movement] == ' ') {
            board[movement] = Char;
            switch (Char) {
                case 'X':
                    return 'O';
                    break;
                case 'O':
                    return 'X';
                    break;
                default:
                    std::cout << "Try again!\n";
                    return Char;
            }
        } else {
            std::cout << "Try again!\n";
            return Char;
        }
    } else {
        std::cout << "Try again!\n";
        return Char;
    }
}

bool checkIfWin(char Char) {
    switch (Char) {
        case 'X':
            Char = 'O';
            break;
        case 'O':
            Char = 'X';
            break;
    }

    for (int i = 0; i < 9; i+=3) {
        if (board[i] == board[i+1] && board[i] == board[i+2] && board[i] != ' ') {
            std::cout << "The player " << Char << " won!\n";
            return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i+3] && board[i] == board[i+6] && board[i] != ' ') {
            std::cout << "The player " << Char << " won!\n";
            return false;
        }
    }
    if (board[0] == board[4] && board[0] == board[8] && board[0] != ' ') {
        std::cout << "The player " << Char << " won!\n";
        return false;
    } else if (board[2] == board[4] && board[2] == board[6] && board[2] != ' ') {
        std::cout << "The player " << Char << " won!\n";
        return false;
    } else {
        return true;
    }
    
}

int main() {
    char Char;
    while (true) {
        std::cout << "Choose the player X or O: ";
        std::cin >> Char;
        if (Char == 'X' || Char == 'O') {
            break;
        } else {
            std::cout << "Try again!\n";
        }
    }
    while (GameRun) {
        DrawBoard();
        GameRun = checkIfWin(Char);
        if (GameRun == false) {
            break;
        }
        Char = move(Char);
    }
    return 0;
}