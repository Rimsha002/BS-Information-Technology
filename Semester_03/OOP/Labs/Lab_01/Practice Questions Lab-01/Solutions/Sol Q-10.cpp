#include<iostream>
#include<string>
using namespace std;


class Rectangle
{
private:    
    int length;
    int width;

public:    
    Rectangle()
    {
        length = 0;
        width = 0;
    }
    void setLength(int l)
    {
        length = l;
    }
    void setWidth(int w)
    {
        width = w;
    }

    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    
    int calculateArea()
    {
        return (length * width);
    }

};

int main()
{
    Rectangle rectangleArray[5];
    for(int i=0;i<5;i++)
    {
        rectangleArray[i].setLength((i+1)*2);
        rectangleArray[i].setWidth((i+1)*3);
    }


    for(int i=0;i<5;i++)
    {
        cout << "Area of " << i+1 << " Rectangle = " << rectangleArray[i].calculateArea() << endl;
    }
    return 0;
}
