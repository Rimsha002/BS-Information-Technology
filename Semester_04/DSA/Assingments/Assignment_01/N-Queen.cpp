#include <iostream>
#include "N-Queen.h"
using namespace std;
int main()
{
    cout << "\nWelcome to N-Queen Problem" << endl;
    cout  << endl;


    int N;
    cout << "Enter the size of the chessboard: ";
    cin >> N;

    NQueen<int> nQueen(N);

    cout << "Initial Board: " << endl;
    nQueen.printSolution();
    cout << "\nwith Solution: " << endl;
    nQueen.solveNQueens();
    // nQueen.printSolution();

    return 0;
}