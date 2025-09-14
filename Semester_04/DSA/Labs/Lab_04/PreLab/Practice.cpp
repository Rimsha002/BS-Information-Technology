#include <iostream>
#include <exception>
using namespace std;

template <class T, int MAX_SIZE>
class Stack {
private:
    T stk[MAX_SIZE];   
    int currentSize;   

public:
    // Default constructor
    Stack() {
    currentSize = 0;
    }

    // Copy constructor
    Stack(const Stack<T, MAX_SIZE>& stk1) {
        currentSize = stk1.currentSize;
        for (int i = 0; i < currentSize; i++) {
            stk[i] = stk1.stk[i];
        }
    }

    void push(const T& val) {
        if (isFull()) {
            throw overflow_error("Stack overflow: cannot push element, the stack is full.");
        }
        currentSize++;
        stk[currentSize] = val; // 
    }

    // Pop operation: Removes the top element from the stack
    T pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow: cannot pop element, the stack is empty.");
        }
        currentSize--;
        return stk[currentSize];  
    }

    // Top operation
    T top() const {
        if (isEmpty()) {
            throw underflow_error("Stack underflow: cannot retrieve top element, the stack is empty.");
        }
        return stk[currentSize - 1];  
    }

    // Check is empty
    bool isEmpty() const {
        if(currentSize == 0){
            return true;
        }
        else{
            return false;
        }
       
    }

    // Check is full
    bool isFull() const {
        if(currentSize == MAX_SIZE){
            return true;
        }
        else{
            return false;
        }
    }

    int getCapacity() const {
        return MAX_SIZE;
    }

    int getNoOfElements() const {
        return currentSize;
    }

    // Assignment operator
    Stack& operator=(const Stack<T, MAX_SIZE>& stk1) {
        if (this != &stk1) {  // Self-assignment check
            currentSize = stk1.currentSize;
            for (int i = 0; i < currentSize; ++i) {
                stk[i] = stk1.stk[i];
            }
        }
        return *this;
    }
};

int main() {
    try {
        Stack<int, 5> stk; 
        Stack<int, 5> stk2; 

        cout << "Capacity of Stack is: " << stk.getCapacity() << endl;
        cout << "Elements in Stack is: " << stk.getNoOfElements() << endl;

        for (int i = 1; i <= 5; i++) {
            stk.push(i);
            cout << "Pushed: " << i << endl;
        }

        cout << "Top element: " << stk.top() << endl;

        cout << "Elements in Stack after pushing: " << stk.getNoOfElements() << endl;

        //Assignmet operator
        stk2 = stk;  
        cout << "Elements in Stack2 after assignment: " << stk2.getNoOfElements() << endl;
        cout << "Top element in Stack2: " << stk2.top() << endl;

        //Poping
        cout << "\nPoping elements from Stack" << endl;
        while (!stk.isEmpty()) {
            cout << "Popped: " << stk.pop() << endl;
        }

        cout << "Elements in Stack after popping: " << stk.getNoOfElements() << endl;

       

    } catch (const exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
