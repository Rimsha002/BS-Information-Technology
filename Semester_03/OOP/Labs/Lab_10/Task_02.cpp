#include <iostream>
// #include <algorithm>
using namespace std;

class Circle
{
    int radius;

public:
    // Defualt Constructor
    Circle()
    {
        radius = 0;
    }

    // Parametrize Constructor
    Circle(int radius)
    {
        setRadius(radius);
    }

    // Setter
    void setRadius(int radius)
    {
        if (radius < 0)
        {
            while (radius < 0)
            {
                cout << "Invalid radius" << endl;
                cout << "Enter again: ";
                cin >> radius;
            }
        }
        this->radius = radius;
    }

    int getRadius()
    {
        return radius;
    }

    virtual void display()
    {
        cout << "It is a circle" << endl;
    }

    void area()
    {
        double area;
        area = 3.14 * (radius * radius);
        cout << "Area of Cicle is: " << area << endl;
    }
};

class Cylinder : public Circle
{
public:
    int height;
    int w;
    Cylinder() : Circle(){};
    Cylinder(int h, int w) : Circle(w)
    {
    }

 // Setter
    void setHeight(int height)
    {
        if (height < 0)
        {
            while (height < 0)
            {
                cout << "Invalid height" << endl;
                cout << "Enter again: ";
                cin >> height;
            }
        }
        this->height = height;
    }

    int getHeight()
    {
        return height;
    }

      void setWidth(int width)
    {
        if (width < 0)
        {
            while (width < 0)
            {
                cout << "Invalid width" << endl;
                cout << "Enter again: ";
                cin >> width;
            }
        }
        this->w = width;
    }

    int getwidth()
    {
        return w;
    }

    void display() override
    {
        cout << "Cylinder is circle" << endl;
    }

    void areaCylinder()
    {
        double area;
        int r = getRadius();
        area = 2 * 3.14 * r * (height * w);
        cout << "Area of Cylinder is: " << area << endl;
    }
};

// class Shpere
class Sphere : public Circle
{
public:
    Sphere() : Circle(){};

    Sphere(int radius) : Circle(radius)
    {
        setRadius(radius);
    }

    void display() override
    {
        cout << "Sphere is circle" << endl;
    }

    void areaSphere()
    {
        double area;
        int r = getRadius();
        area = 4 * 3.14 * r * r;
        cout << "Area of Cylinder is: " << area << endl;
    }
};

int main()
{
    Circle c;
    c.setRadius(5);
    c.area();
    c.display();
    cout << endl;

    Cylinder cylinder;
    cylinder.setHeight(4);
    cylinder.setWidth(3);
    cylinder.areaCylinder();
    cylinder.display();
    cout << endl;

    Sphere sphere;
    sphere.setRadius(6);
    sphere.areaSphere();
    sphere.display();
    cout << endl;
}