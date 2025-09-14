#include <iostream>
#include <vector>
using namespace std;

void input(vector <int> , int );
vector<int> input(int size);
void display(int);

int main ()
{
    vector <int> v;
    int size = v.size();
    // cout << size;
    input(v, size);
  
    // display(v);

    return 0;
}

void input(vector<int> v, int size)
{
    for(int i = 0 ; i < size; i ++)
    {
    cout << "Enter element for vector: ";
    v.push_back(i);
    size++;
    }

       for (int num : v) {
        cout << num << " ";
    }
}

// vector<int> input(int size) {
//     vector<int> arr(size); 
//     cout << "Enter " << size << " integers:\n";
//     for (int i = 0; i < size; i++) {
//         cin >> arr[i];
//         size++;
//     }
//     return arr;
// }

// Function to display the contents of an array
void display(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
