#include <iostream>
#include <cstdlib>  // For rand and srand
#include <ctime>    // For time
using namespace std;

void allocateArray(int*** &arr, int n = 3) {
    arr = new int**[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int*[n];
        for (int j = 0; j < n; ++j) {
            arr[i][j] = new int[n];
        }
    }
}

void initializeArray(int*** arr, int n = 3) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                *(*(arr[i] + j) + k) = rand() % 100; // Using pointer notation
            }
        }
    }
}

void printArray(int*** arr, int n = 3) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cout << *(*(arr[i] + j) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void deallocateArray(int*** &arr, int n = 3) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;  // Avoiding dangling pointer
}

int main() {
    int*** arr;
    allocateArray(arr);
    initializeArray(arr);
    cout << "3D Array Elements:\n";
    printArray(arr);
    deallocateArray(arr);
    return 0;
}





// #include <iostream>
// using namespace std;

// void allocateArray(int ***&arr, int n );
// void initializeArray(int ***arr, int n );
// void printArray(int ***arr, int n);
// void deallocateArray(int ***arr, int n);

// int main()
// {
//     int ***arr;
//     allocateArray(arr, 2);
//     initializeArray(arr, 2);
//     printArray(arr, 2);
//     deallocateArray(arr, 2);

//     return 0;
// }

// void allocateArray(int ***&arr, int n)
// {
//     arr = new int **[n];

//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = new int *[n];
//         for (int j = 0; j < n; j++)
//         {
//             arr[i][j] = new int[n];
          
//         }
//     }
//     cout << "\nArray Allocated successfully " << endl;
// }

// void initializeArray(int ***arr, int n)
// {
//     int element = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             for (int k = 0; k < n; k++)
//             {
//                 // cout << "Enter element for: " << "arr["<< i << "]["<< j << "]["<< k << "]: " ;

//                 arr[i][j][k] = element++;
            
//             }
//         }
//     }

//     cout << "Array initialize Successfully" << endl;
// }

// void printArray(int ***arr, int n)
// {
//     cout << "Print start" << endl;
//     for (int i = 0; i < n; i++)
//     {
        
//         for (int j = 0; j < n; j++)
//         {
//             for (int k = 0; k < n; k++)
//             {
//                 // cout << arr[i][j][k] << " ";
//                 cout << *(*(*arr + i) +j)+k << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }

// }

// void deallocateArray(int ***arr, int n )
// {
//     for (int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < n ; j++)
//         {
//             delete[] arr[i][j];
//         }
        
//     }
//     delete[] arr;

// }