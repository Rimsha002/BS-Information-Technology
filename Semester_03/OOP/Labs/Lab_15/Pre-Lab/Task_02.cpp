#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class MyPoint
{
private:
    double x, y;

public:
    // Constructor to initialize x and y
    MyPoint(int x, int y)
    {
          if (x > 0 && y < 0)
        {
            throw out_of_range("Invalid! Y must be positive if x is positive");
        }

        if (x < 0 && y < 0)
        {
            throw underflow_error("Invalid! Both x and y must be positive");
        }
    
      if (x < 0)
        {
            throw runtime_error("Invalid! x must be positive");
        }
        this->x = x;
        this->y = y;
        
    }

    // Setter for x with validation
    void setX(int x)
    {
        if (x < 0)
        {
            throw runtime_error("Invalid! x must be positive");
        }
        this->x = x;
    }

    // Setter for y with validation
    void setY(int x, int y)
    {
        if (x < 0 && y < 0)
        {
            throw underflow_error("Invalid! Both x and y must be positive");
        }
         if (x > 0 && y < 0)
        {
            throw out_of_range("Invalid! Y must be positive if x is positive");
        }
        this->y = y;
    }

    // Getter for x
    int getX()
    {
        return x;
    }

    // Getter for y
    int getY()
    {
        return y;
    }

    // Display method to print x and y
    void display()
    {
        cout << "x: " << x << " y: " << y << endl;
    }
};

int main()
{
    cout << "Task 2: Object Constructor" << endl;
    try
    {
        cout << "Enter value of 1st point: ";
        int x, y;
        cin >> x;
        cout << "Enter value of 2nd point: ";
        cin >> y;

        MyPoint p1(x, y);
        p1.display();
    }
    catch (const underflow_error &e)
    {
        cout << e.what() << endl;
    }
    catch (const out_of_range &e)
    {
        cout << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    //Display
   
    return 0;
}
