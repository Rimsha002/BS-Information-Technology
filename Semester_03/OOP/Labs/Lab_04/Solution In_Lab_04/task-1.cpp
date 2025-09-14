#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point() : x(0), y(0) {}

    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    void display()
    {
        cout << "x: " << this->x << " y: " << this->y << endl;
    }
};

class Line
{
    Point starting_point;
    Point ending_point;

public:
    Line(int x1, int y1, int x2, int y2)
    {
        starting_point.setX(x1);
        starting_point.setY(y1);
        ending_point.setX(x2);
        ending_point.setY(y2);
    }
    void display_line()
    {
        starting_point.display();
        ending_point.display();
    }
};
int main()
{
    int x1,y1,x2,y2;
    cout<<"Enter X1 of line 1: ";
    cin>>x1;
    cout<<"Enter Y1 of line 1: ";
    cin>>y1;
    cout<<"Enter X1 of line 1: ";
    cin>>x2;
    cout<<"Enter Y1 of line 1: ";
    cin>>y2;
    Line line_one(x1,y1,x2,y2);

    cout<<"Enter X1 of line 2: ";
    cin>>x1;
    cout<<"Enter Y1 of line 2: ";
    cin>>y1;
    cout<<"Enter X1 of line 2: ";
    cin>>x2;
    cout<<"Enter Y1 of line 2: ";
    cin>>y2;

    Line line_two(x1, y1, x2, y2);

    cout<<"Line 1: "<<endl;
    line_one.display_line();
    cout<<endl;
    cout<<"Line 2: "<<endl;
    line_two.display_line();

    return 0;
}
