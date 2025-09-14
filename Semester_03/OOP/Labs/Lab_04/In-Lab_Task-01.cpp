#include <iostream>
using namespace std;
class PointX
{
private:
    int x1;
    int x2;

public:
    // PointX(int x1 = 0, int x2)
    // {
    //     this->x1 = x1;
    //     this->x2 = x2;
    // }
    int setX1(int x1)
    {
        this->x1 = x1;
    }
    int setX2(int x2)
    {
        this->x2 = x2;
    }
    const int getX1()
    {
        return x1;
    }
    const int getX2()
    {
        return x2;
    }
};
class PointY
{
    private:
    int y1;
    int y2;

public:
    // PointY(int y1 = 0, int y2)
    // {
    //     this->y1 = y1;
    //     this->y2 = y2;
    // }
    int setY1(int y1)
    {
        this->y1 = y1;
    }
    int setY2(int y2)
    {
        this->y2 = y2;
    }
    const int getY1()
    {
        return y1;
    }
    const int getY2()
    {
        return y2;
    }
};
class Line
{
    PointX objX;
    PointY objY;
private:
    int startPointX;
    int startPointY;
    int endPointX;
    int endPointY;

public:
    Line(int startPointX = 0, int startPointY = 0, int endPointX = 0, int endPointY = 0)
    {
        this->startPointX = objX.setX1(startPointX);
        this->startPointY = objY.setY1(startPointY);
        this->endPointX = objX.setX2(endPointX);
        this->endPointY = objY.setY2(endPointY);
    }

void setStartX(int startPointX)
{
this->startPointX = objX.setX1(startPointX);
}
void setStartY(int startPointY)
{
this->startPointY = objY.setY1(startPointY);
}
void setEndX(int endPointX)
{
this->endPointX = objX.setX2(endPointX);
}
void setEndY(int endPointY)
{
this->endPointY = objY.setY2(endPointY);
}
void display()
{
    cout << "X1 : " << objX.getX1() << endl ;
    cout << "Y1 : " << objY.getY1() << endl ;
    cout << "X2 : " << objX.getX2() << endl ;
    cout << "X2 : " << objY.getY2() << endl ;
}

};

int main()
{
    Line lineObj(10,30, 40, 50);
    Line lineObj2(23, 40, 50, 70);
    cout << "Line 1" << endl;
    lineObj.display();
    cout << "\nLine 02" << endl;
    lineObj2.display();

    return 0;
}