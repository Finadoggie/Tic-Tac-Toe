#include <stdio.h>
#include <stdlib.h>

void DrawBoard(char board[9])
{
    system("cls");
    printf(" %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

void DoWinner(char board[9], int player)
{
    DrawBoard(board);
    printf("Player %d wins!\n\nPress any key to play again", player);
    fflush(stdin);
    getchar();
}

int main(void)
{
    char board[9];
    int space;
    char mark;
    while(1)
    {
        for (int i = 0; i < 9; i++) board[i] = ' '; // Resets the board before starting the game
        while (1)
        {   
            for(int player = 1; player <= 2; player++)
            {
                while(1){ 
                    DrawBoard(board); // Draw Board
            
                    // Ask player to mark a space       
                    printf("Player %d: Select a space to mark (1-9 = left-right, top-bottom): ", player);
                    fflush(stdin);
                    scanf("%d", &space);
                    if(board[space - 1] == ' ') break; // Loops until player selects a valid space
                }

                mark = player == 1 ? 'x' : 'o'; // Set the mark used by the player
                board[space - 1] = mark;        // Mark the desired space

                
                // Check for a win
                for(int i = 0, a; i <= 2; i++)
                {
                    if(board[i] == mark && board[i + 3] == mark && board[i + 6] == mark)
                    {
                        DoWinner(board, player);
                        goto EndGame;
                    }
                    a = 3 * i;
                    if(board[a] == mark && board[a + 1] == mark && board[a + 2] == mark)
                    {
                        DoWinner(board, player);
                        goto EndGame;
                    }
                }
                if(board[0] == mark && board[4] == mark && board[8] == mark)
                {
                    DoWinner(board, player);
                    goto EndGame;
                }
                if(board[2] == mark && board[4] == mark && board[6] == mark)
                {
                    DoWinner(board, player);
                    goto EndGame;
                }
            }
        }
        EndGame: ;
    }
}