#include <iostream>
using namespace std;

//Unsorted List ADT and implement it as class template
template <class T>
class UnsortedList
{
public:
    UnsortedList();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void InsertItem(T);
    void DeleteItem(T);
    void RetrieveItem(T, bool &);
    void ResetList();
    void GetNextItem(T &);
    ~UnsortedList();


private:
    int length;
    T *info;
    int currentPos;
};

template <class T>
UnsortedList<T>::UnsortedList()
{
    length = 0;
    info = new T[5];
    currentPos = -1;
}

template <class T>
UnsortedList<T>::~UnsortedList()
{
    delete[] info;
}

template <class T>
void UnsortedList<T>::MakeEmpty()
{
    length = 0;
}

template <class T>
bool UnsortedList<T>::IsFull()
{
    return length == 5;
}

template <class T>
int UnsortedList<T>::LengthIs()
{
    return length;
}

template <class T>
void UnsortedList<T>::InsertItem(T item)
{
    info[length] = item;
    length++;
}

template <class T>
void UnsortedList<T>::DeleteItem(T item)
{
    int location = 0;
    while (item != info[location])
        location++;
    info[location] = info[length - 1];
    length--;
}

template <class T>
void UnsortedList<T>::RetrieveItem(T item, bool &found)
{
    int location = 0;
    found = false;
    while (location < length)
    {
        if (item == info[location])
        {
            found = true;
            item = info[location];
            return;
        }
        location++;
    }
}

template <class T>
void UnsortedList<T>::ResetList()
{
    currentPos = -1;
}

template <class T>
void UnsortedList<T>::GetNextItem(T &item)
{
    currentPos++;
    item = info[currentPos];
}



int main()
{
    UnsortedList<int> list;
    list.InsertItem(5);
    list.InsertItem(7);
    list.InsertItem(6);
    list.InsertItem(9);
    list.InsertItem(8);

    int item;
    list.ResetList();
    for (int i = 0; i < list.LengthIs(); i++)
    {
        list.GetNextItem(item);
        cout << item << " ";
    }
    cout << endl;

    list.DeleteItem(7);
    list.ResetList();
    for (int i = 0; i < list.LengthIs(); i++)
    {
        list.GetNextItem(item);
        cout << item << " ";
    }
    cout << endl;

    bool found;
    list.RetrieveItem(6, found);
    if (found)
        cout << "Item found" << endl;
    else
        cout << "Item not found" << endl;

    list.RetrieveItem(7, found);
    if (found)
        cout << "Item found" << endl;
    else
        cout << "Item not found" << endl;

    
    

   return 0;
}