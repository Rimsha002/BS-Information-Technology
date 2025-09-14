#include<iostream>
#include<string>
using namespace std;


class Rectangle
{
public:    
    int length;
    int width;
    
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
        rectangleArray[i].length = (i+1)*2;
        rectangleArray[i].width = (i+1)*3;
    }


    for(int i=0;i<5;i++)
    {
        cout << "Area of " << i+1 << " Rectangle = " << rectangleArray[i].calculateArea() << endl;
    }
    return 0;
}
