
def print_board(board):
    print("\n")
    for i in range(3):
        for j in range(3):
            print(board[i][j], end=" ")
            if j < 2:
                print("|", end=" ")
        print()
        if i < 2:
            print("---------")
    print("\n")

def check_win(board, player):
    for i in range(3):
        if all([board[i][j] == player for j in range(3)]) or \
           all([board[j][i] == player for j in range(3)]):
            return True
    if board[0][0] == player and board[1][1] == player and board[2][2] == player:
        return True
    if board[0][2] == player and board[1][1] == player and board[2][0] == player:
        return True
    return False

def check_draw(board):
    for row in board:
        for cell in row:
            if cell != 'X' and cell != 'O':
                return False
    return True

def player_move(board, player):
    while True:
        try:
            move = int(input(f"Player {player}, enter your move (1-9): "))
            if move < 1 or move > 9:
                print("Invalid move! Please enter a number between 1 and 9.")
                continue
            row, col = (move - 1) // 3, (move - 1) % 3
            if board[row][col] == 'X' or board[row][col] == 'O':
                print("This spot is already taken! Try another one.")
            else:
                board[row][col] = player
                break
        except ValueError:
            print("Invalid input! Please enter a number between 1 and 9.")

def main():
    board = [[str(i + 1) for i in range(3 * j, 3 * (j + 1))] for j in range(3)]  
    current_player = 'X'
    
    print("Welcome to Tic Tac Toe!")
    print_board(board)

    while True:
        player_move(board, current_player)
        print_board(board)

        if check_win(board, current_player):
            print(f"Player {current_player} wins!")
            break
        elif check_draw(board):
            print("It's a draw!")
            break

        current_player = 'O' if current_player == 'X' else 'X'

if __name__ == "__main__":
    main()



OUTPUT :
Welcome to Tic Tac Toe!


1 | 2 | 3 
---------
4 | 5 | 6 
---------
7 | 8 | 9 


Player X, enter your move (1-9): 9


1 | 2 | 3 
---------
4 | 5 | 6 
---------
7 | 8 | X 


Player O, enter your move (1-9): 5


1 | 2 | 3 
---------
4 | O | 6 
---------
7 | 8 | X 


Player X, enter your move (1-9): 1


X | 2 | 3 
---------
4 | O | 6 
---------
7 | 8 | X 


Player O, enter your move (1-9): 2


X | O | 3 
---------
4 | O | 6 
---------
7 | 8 | X 


Player X, enter your move (1-9): 3


X | O | X 
---------
4 | O | 6 
---------
7 | 8 | X 


Player O, enter your move (1-9): 4


X | O | X 
---------
O | O | 6 
---------
7 | 8 | X 


Player X, enter your move (1-9): 7


X | O | X 
---------
O | O | 6 
---------
X | 8 | X 


Player O, enter your move (1-9): 6


X | O | X 
---------
O | O | O 
---------
X | 8 | X 


Player O wins!
