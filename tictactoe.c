#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void display_board(char board[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int* get_player_move()
{
    static int arr[2];
    printf("Your turn, enter an x y coord: ");
    scanf(" %d %d", &arr[0], &arr[1]);
    return arr;
}

bool is_valid_move(int arr[2], char board[3][3])
{
    if (arr[0] < 0 || arr[0] > 2 || arr[1] < 0 || arr[1] > 2) return false;
    if(board[arr[0]][arr[1]] == '.') return true;
    else return false;
}

void make_move(int arr[2], char board[3][3], char player)
{
    board[arr[0]][arr[1]] = player;
}

bool check_winner(char board[3][3])
{
    // Check rows and columns in one loop
    for (int i = 0; i < 3; i++) {
        // Check row i
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') return true;
        // Check column i
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.') return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') return true;

    return false;
}

bool is_board_full(char board[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (board[i][j] == '.') return false;
        }
    }
    return true;
}

int main(void)
{
    char board[3][3] = {
    {'.', '.', '.'},
    {'.', '.', '.'},
    {'.', '.', '.'}
    };

    char current_player = 'X';

    while(true) {
        display_board(board);
        int *move = get_player_move();
        if (is_valid_move(move, board)) {
            make_move(move, board, current_player);
            if (check_winner(board)) break;
            if (is_board_full(board)) break;
            current_player = (current_player == 'X') ? 'O' : 'X';
        }
    }

    display_board(board);
    printf("%c player wins!", (current_player == 'X') ? 'X' : 'O');

    return (0);
}

