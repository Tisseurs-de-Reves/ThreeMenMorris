
#include "morrisboard.h"
#include <iostream>
using namespace std;

int main() {
    
    int board = 0;
    printBoard(board);

    int counter, input, fromPos, toPos  = 0;
    int winFlag = 0;
    int i = 1;

    while (counter < 6){

        cout << "Player " << i << "(1-9): ";
        cin >> input;
        while (input < 1 || input > 9 || boardState(board, input) != 0){
            cout << "Invalid. Try again!" << endl;
            cout << "Player " << i << " (1-9): ";
            cin >> input;
        }

        placePiece(board , input, i);
        printBoard(board);

        if (formLine(board) == 1){
            cout << "Player 1 Wins!";
            winFlag = 1;
            break;
        }
        
        else if (formLine(board) == 2 )
        {
            cout << "Player 2 Wins!";
            winFlag = 1;
            break;
        }
        counter += 1;

        if ( i == 1 ){
            i = 2 ;
        }
        else {i = 1;};
    }
    

    while (winFlag == 0){
        cout << "Player " << i << "(from to): ";
        cin >> fromPos >> toPos;

        while (fromPos < 1 || fromPos > 9 || toPos < 1 || toPos > 9 || boardState(board, fromPos) != i || boardState(board, toPos) != 0 ){
            cout << "Invalid. Try again!" << endl;
            cout << "Player " << i << " (from to): ";
            cin >> fromPos >> toPos;
        }

        movePiece(board, fromPos, toPos, i);
        printBoard(board);

        if (formLine(board) == 1){
            cout << "Player 1 Wins!";
            winFlag = 1;
        }
        
        else if (formLine(board) == 2 )
        {
            cout << "Player 2 Wins!";
            winFlag = 1;
        }
        counter += 1;

        if ( i == 1 ){
            i = 2 ;
        }
        else {i = 1;};
    }
}
