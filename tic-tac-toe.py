import math
board = [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']  # array

GameRun = True


def DrawBoard():
    print(f" {board[0]} | {board[1]} | {board[2]} ")
    print("-----------")
    print(f" {board[3]} | {board[4]} | {board[5]} ")
    print("-----------")
    print(f" {board[6]} | {board[7]} | {board[8]} ")


def move(char):
    try:
        movement = int(
            input(f"Player {char} Enter the position between [0-8]:"))

        if board[movement] == ' ':
            board[movement] = char
            if char == 'X':
                return 'O'
            elif char == 'O':
                return 'X'
        else:
            print("Try again")
            return char
    except:
        print("Try again!")
        return char


def checkIfWin(char):
    if char == 'X':
        char = 'O'
    else:
        char = 'X'

    if board[0] == board[1] == board[2] and board[0] != ' ':
        print(f'The player {char} won!')
        return False
    elif board[3] == board[4] == board[5] and board[3] != ' ':
        print(f'The player {char} won!')
        return False
    elif board[6] == board[7] == board[8] and board[6] != ' ':
        print(f'The player {char} won!')
        return False
    elif board[0] == board[4] == board[8] and board[0] != ' ':
        print(f'The player {char} won!')
        return False
    elif board[2] == board[4] == board[6] and board[2] != ' ':
        print(f'The player {char} won!')
        return False
    elif board[0] == board[3] == board[6] and board[0] != ' ':
        print(f'The player {char} won!')
        return False
    elif board[1] == board[4] == board[7] and board[1] != ' ':
        print(f'The player {char} won!')
        return False
    elif board[2] == board[5] == board[8] and board[2] != ' ':
        print(f'The player {char} won!')
        return False
    else:
        return True


while True:
    char = input("Choose the player X or O:")
    if char == 'X':
        char = 'X'
        break
    elif char == 'O':
        char = 'O'
        break
    else:
        print("Try again!")
        char = ''

while GameRun:
    DrawBoard()
    GameRun = checkIfWin(char)
    if GameRun == False:
        break
    char = move(char)
