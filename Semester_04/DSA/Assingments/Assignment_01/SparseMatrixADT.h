#ifndef SPARSEMATRIXADT_H
#define SPARSEMATRIXADT_H

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class SparseMatrixADT
{
private:
   vector<pair<pair<int, int>, T>> matrix;
   int rows;
   int cols;

public:
   SparseMatrixADT();
   SparseMatrixADT(int r, int c);
   SparseMatrixADT(const SparseMatrixADT<T> &m);
   ~SparseMatrixADT();
   SparseMatrixADT<T> &operator=(const SparseMatrixADT<T> &m);
   
   void SetValue(int row, int col, T value);

   T GetValue(int row, int col) const;
   
   void display() const;

   int RecursiveDiagonalSum(int index);
   
   SparseMatrixADT<T> Transpose() const;
  
   SparseMatrixADT<T> Multiply(const SparseMatrixADT<T> &other) const;
   
};

template <class T>
SparseMatrixADT<T>::SparseMatrixADT()
{
   rows = 0;
   cols = 0;
}

template <class T>
SparseMatrixADT<T>::SparseMatrixADT(int r, int c)
{
   rows = r;
   cols = c;
   
}

template <class T>
SparseMatrixADT<T>::SparseMatrixADT(const SparseMatrixADT<T> &m)
{
   rows = m.rows;
   cols = m.cols;
   matrix = m.matrix;
}

template <class T>
SparseMatrixADT<T>::~SparseMatrixADT()
{
   matrix.clear();
}

template <class T>
SparseMatrixADT<T> &SparseMatrixADT<T>::operator=(const SparseMatrixADT<T> &m)
{
   if(m != *this)
   {
      matrix.clear();
      rows = m.rows;
      cols = m.cols;

      matrix = m.matrix;
  
   }
   return *this;
}

// template <class T>
// void SparseMatrixADT<T>::SetValue(int row, int col, T value)
// {
//    matrix[row*cols + col].second = value;
// }

template <class T>
void SparseMatrixADT<T>::SetValue(int row, int col, T value)
{
   bool found = false;
   for (auto &element : matrix)
   {
      if (element.first.first == row && element.first.second == col)
      {
         element.second = value;
         found = true;
         break;
      }
   }
   if (!found)
   {
      matrix.push_back({{row, col}, value});
   }
}

template <class T>
T SparseMatrixADT<T>::GetValue(int row, int col) const
{
   for(const auto &element : matrix)
   {
      if(element.first.first == row && element.first.second == col)
      {
         return element.second;
      }
   }
   return 0;
}


template <class T>
void SparseMatrixADT<T>::display() const
{
   cout << "Matrix: " << endl;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         bool found = false;
         for (const auto &element : matrix)
         {
            if (element.first.first == i && element.first.second == j)
            {
               cout << element.second << "  ";
               found = true;
               break;
            }
         }
         if (!found)
         {
            cout << "0  ";
         }
      }
      cout << endl;
   }

   cout << endl;
}

template <class T>
int SparseMatrixADT<T>::RecursiveDiagonalSum(int index)
{
   if(rows != cols)
   {
      cout << "Matrix is not square matrix. So," << endl;
      return 0;
   }
   if(index == matrix.size())
   {
      return 0;
   }
   if(matrix[index].first.first == matrix[index].first.second)
   {
      return matrix[index].second + RecursiveDiagonalSum(index + 1);
   }


   return RecursiveDiagonalSum(index + 1);
}

template <class T>
SparseMatrixADT<T> SparseMatrixADT<T>::Transpose() const
{
  SparseMatrixADT <T> newMatrix(cols, rows);
   for(const auto &element : matrix)
   {
      newMatrix.SetValue(element.first.second, element.first.first, element.second);
   }
   return newMatrix;
}

template <class T>
SparseMatrixADT<T> SparseMatrixADT<T>::Multiply(const SparseMatrixADT<T> &M1) const
{
   if(cols != M1.rows)
   {
      cout << "Matrix multiplication is not possible." << endl;
      return SparseMatrixADT<T>();
   }

   SparseMatrixADT<T> result(rows, M1.cols);
   for(int i = 0; i < rows; i++)
   {
      for(int j = 0; j < M1.cols; j++)
      {
         T sum = 0;
         for(int k = 0; k < cols; k++)
         {
            sum += GetValue(i, k) * M1.GetValue(k, j);
         }
         result.SetValue(i, j, sum);
      }
   }
   return result;
}



#endif
