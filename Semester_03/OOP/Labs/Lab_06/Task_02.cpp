#include <iostream>
using namespace std;


class Square{
int side;
int area;
// friend class Rectangle;

public:
void findarea()
{
    
    area = Rectangle.width * Rectangle.height;
    cout << "area of Rectange is: "<< area;

}

};

class Rectangle{
int height;
int width;
// int area;
friend class Square;
public:
Rectangle()
{
    height = 0;
    width = 0;
    // area = 0;
}

};

int main()
{
   return 0;
}