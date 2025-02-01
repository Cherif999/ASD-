#include <stdio.h>

char board[3][3];

void init_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void print_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
}

int check_winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return 1;
    return 0;
}

int is_draw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

void play_game() {
    int row, col, turn = 0;
    init_board();
    while (1) {
        print_board();
        printf("Player %d, enter row and column (0-2): ", turn % 2 + 1);
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row][col] = (turn % 2 == 0) ? 'X' : 'O';
        if (check_winner()) {
            print_board();
            printf("Player %d wins!\n", turn % 2 + 1);
            break;
        }
        if (is_draw()) {
            print_board();
            printf("It's a draw!\n");
            break;
        }
        turn++;
    }
}

int main() {
    play_game();
    return 0;
}
