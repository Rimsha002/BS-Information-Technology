#include <iostream>
using namespace std;

class Shape
{
    int length;
    int width;
public:
    // Defualt Constructor
    Shape()
    {
        length = 0;
        width = 0;
    }

    // Parametrize Constructor
    Shape(int length, int width)
    {
        setLength(length);
        setWidth(width);
    }

    // Setter
    void setLength(int length)
    {
        if (length < 0)
        {
            while (length < 0)
            {
                cout << "Invalid length" << endl;
                cout << "Length again: ";
                cin >> length;
            }
        }
        this->length = length;
    }

    void setWidth(int width)
    {
        if (width < 0)
        {
            while (width < 0)
            {
                cout << "Invalid width" << endl;
                cout << "Width again: ";
                cin >> width;
            }
        }
        this->width = width;
    }

    // Getter
    int getLength()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

     virtual void display()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    
    }

};
//class Rectangle
class Rectangle : public Shape
{
    public:
    // Constructor
    Rectangle(int length, int width) : Shape(length, width)
    {
        setLength(length);
        setWidth(width);
    }
     

    void display() override
    {
        cout << "Length: " << getLength() << endl;
        cout << "Width: " << getWidth() << endl;
        cout << "Area: " << getLength() * getWidth() << endl;      
    }
};

//class Shpere
class Square : public Shape
{
    public:
    // Constructor
    Square(double side) : Shape(side, side)
    {
        setLength(side);
        setWidth(side);
    }
  

    void display() override
    {
        cout << "Side is: " << getLength() << endl;
        cout << "Area: " << getLength() * getWidth() << endl;      
    }
};


int main()
{
    int choice;
    cout << "For which Shape you want to enter data \n 1. Rectangle \n 2. Square \n Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int length, width;
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;

        Rectangle r1(length, width);
        r1.display();
        break;
    }
    case 2:
    {
        int side;
        cout << "Enter side: ";
        cin >> side;

        Square sp1(side);
        sp1.display();
        break;
    }
    
    default:
    {
        cout << "Invalid Choice" << endl;
    }
     
    }

    return 0;
}