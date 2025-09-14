#ifndef NQUEEN_H
#define NQUEEN_H
#include <iostream>
using namespace std;

template <class T>
class NQueen
{
private:
   int N; 
   char **board;                   
   bool isBound(int row, int col);
   bool isSafe(int row, int col); 
   bool solve(int row);           
public:
   NQueen();             
   NQueen(int n);        
   ~NQueen();            
   void solveNQueens();  
   void printSolution(); 
};

template <class T>
NQueen<T>::NQueen()
{
   N = 0;
   board = nullptr;
}


template <class T>
NQueen<T>::NQueen(int n)
{
   N = n;
   board = new char*[N];
   for(int i = 0; i < N; i++)
   {
      board[i] = new char[N];
      for(int j = 0; j < N; j++)
      {
      board[i][j] = '.' ;
      }
   }
}

template <class T>
NQueen<T>::~NQueen()
{
   delete[] board;
}

template <class T>
bool NQueen<T>::isBound(int row, int col)
{
   
   if(row<0 || col<0 || row>=N || col>=N)
   {
      return false;
   }
   return true;
}

template <class T>
bool NQueen<T>::isSafe(int row, int col)
{
   for(int i = 0; i < row; i++)
   {
      if(board[i][col] == 'Q' || board[row][i] == 'Q')
      {
         return false;
      }
   }

   for(int i = 0; i< N; i++)  
   {
      if(isBound(row - i, col - i) && board[row - i][col - i] == 'Q') return false;

      if(isBound(row - i, col + i) && board[row - i][col + i] == 'Q') return false;

      if(isBound(row + i, col - i) && board[row + i][col - i] == 'Q') return false;

      if(isBound(row + i, col + i) && board[row + i][col + i] == 'Q') return false;
      
   }

   return true;
}


template <class T>
bool NQueen<T>::solve(int row)
{
   if(row == N)
   {
      return true;
   }

   for(int i = 0; i < N; i++)
   {
      if(isSafe(row, i))
      {
         board[row][i] = 'Q';
         if(solve(row + 1))
         {
            return true;
         }
         board[row][i] = '.';
      }
   }

   return false;
}

template <class T>
void NQueen<T>::solveNQueens()
{
   if(solve(0))
   {
      printSolution();
   }
   else
   {
      cout << "Solution does not exist." << endl;
   }
}

template <class T>
void NQueen<T>::printSolution()
{
   for(int i = 0; i < N; i++)
   {
      for(int j = 0; j < N; j++)
      {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
}

#endif
// Spacecomplexity: O(N^2)
// Time complexity: O(N!)