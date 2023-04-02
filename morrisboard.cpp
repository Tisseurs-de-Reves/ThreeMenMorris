
#include "morrisboard.h"
#include <iostream>
using namespace std;

/* Returns the state of position pos of the game board.*/
int boardState(int board, int pos) {
    for (int i = 0; i < 9 - pos; i++)
        board /= 10;
    return board % 10;
}

/* Prints the board to the screen.*/
void printBoard(int board) {
    cout << boardState(board, 1) << "-" << boardState(board, 2) << "-" << boardState(board, 3) << endl;
    cout << "|\\|/|\n";
    cout << boardState(board, 4) << "-" << boardState(board, 5) << "-" << boardState(board, 6) << endl;
    cout << "|/|\\|\n";
    cout << boardState(board, 7) << "-" << boardState(board, 8) << "-" << boardState(board, 9) << endl;
}

/* Perform the task of player p placing a piece to position pos of board. */
void placePiece(int &board, int pos, int p) {

    int p_old = boardState(board, pos);
    int p_new = p;
    for (int  i = 0; i < 9 - pos; i++){
        p_old = p_old * 10;
        p_new = p_new * 10;
    }

    board = board - p_old + p_new;

}

/* Perform the task of player p moving a piece from position from to position
   to of board. */
void movePiece(int &board, int from, int to, int p) {

    placePiece(board, from, 0);
    placePiece(board, to, p);

}

/* Checks if any player has formed a line horizontally, vertically, or
   diagonally in board. */
int formLine(int board) {

    int winner = 0;
    if ((boardState(board, 1) == boardState(board,4) && boardState(board,4) == boardState(board,7) && boardState(board,7)  == 1) || 
        (boardState(board, 2) == boardState(board,5) && boardState(board,5) == boardState(board,8) && boardState(board,8)  == 1) ||
        (boardState(board, 3) == boardState(board,6) && boardState(board,6) == boardState(board,9) && boardState(board,9)  == 1) ||
        (boardState(board, 1) == boardState(board,2) && boardState(board,2) == boardState(board,3) && boardState(board,3)  == 1) ||
        (boardState(board, 4) == boardState(board,5) && boardState(board,5) == boardState(board,6) && boardState(board,6)  == 1) ||
        (boardState(board, 7) == boardState(board,8) && boardState(board,8) == boardState(board,9) && boardState(board,9)  == 1) ||
        (boardState(board, 1) == boardState(board,5) && boardState(board,5) == boardState(board,9) && boardState(board,9)  == 1) ||
        (boardState(board, 3) == boardState(board,5) && boardState(board,5) == boardState(board,7) && boardState(board,7)  == 1))
        {
            winner = 1 ;
    }
    
    if ((boardState(board, 1) == boardState(board,4) && boardState(board,4) == boardState(board,7) && boardState(board,7)  == 2) || 
        (boardState(board, 2) == boardState(board,5) && boardState(board,5) == boardState(board,8) && boardState(board,8)  == 2) ||
        (boardState(board, 3) == boardState(board,6) && boardState(board,6) == boardState(board,9) && boardState(board,9)  == 2) ||
        (boardState(board, 1) == boardState(board,2) && boardState(board,2) == boardState(board,3) && boardState(board,3)  == 2) ||
        (boardState(board, 4) == boardState(board,5) && boardState(board,5) == boardState(board,6) && boardState(board,6)  == 2) ||
        (boardState(board, 7) == boardState(board,8) && boardState(board,8) == boardState(board,9) && boardState(board,9)  == 2) ||
        (boardState(board, 1) == boardState(board,5) && boardState(board,5) == boardState(board,9) && boardState(board,9)  == 2) ||
        (boardState(board, 3) == boardState(board,5) && boardState(board,5) == boardState(board,7) && boardState(board,7)  == 2))
        {
            winner = 2 ;
    }
    return winner;
}
