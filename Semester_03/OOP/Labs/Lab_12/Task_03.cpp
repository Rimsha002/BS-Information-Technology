#include <iostream>
using namespace std;

class Shape
{
protected:
   double width, height;

public:
   Shape(){};

   Shape(double w, double h)
   {
      width = w;
      height = h;
   }

   virtual double areaCalculate() = 0;

   virtual void display() = 0;

   virtual ~Shape(){};
};

// Circle
class Circle : public Shape
{
public:
   Circle() : Shape(){};

   Circle(double r) : Shape(r, r) {}

   double areaCalculate()
   {
      return 3.14 * width * width;
   }

   void display()
   {
      cout << "Circle Area: " << areaCalculate() << endl;
   }

   ~Circle(){};
};

// Square
class Square : public Shape
{
public:
   Square() : Shape(){};

   Square(double s) : Shape(s, s) {}

   double areaCalculate()
   {
      return width * width;
   }

   void display()
   {
      cout << "Square Area: " << areaCalculate() << endl;
   }

   ~Square(){};
};

// Triangle
class Triangle : public Shape
{
public:
   Triangle() : Shape(){};

   Triangle(double b, double h) : Shape(b, h) {}

   double areaCalculate()
   {
      return 0.5 * width * height;
   }

   void display()
   {
      cout << "Triangle Area: " << areaCalculate() << endl;
   }

   ~Triangle(){};
};

int main()
{
   Shape *s1;

   int choice;
   cout << "Which shape do you want to insert? \n1. Circle\n2. Square\n3. Triangle\n Enter your choice or -1 to quite: "
        << endl;

   cin >> choice;

   while (choice != -1)
   {
      switch (choice)
      {
      case 1:
         cout << "Enter the radius of the circle: ";
         double r;
         cin >> r;

         s1 = new Circle(r);
         cout << "Circle created." << endl;
         s1->areaCalculate();
         s1->display();
         break;

      case 2:
         cout << "Enter the side of the square: ";
         double s;
         cin >> s;
         
         s1 = new Square(s);
         cout << "Square created." << endl;
         s1->areaCalculate();
         s1->display();
         break;

      case 3:

         cout << "Enter the base and height of the triangle: ";
         double b, h;
         cin >> b >> h;

         s1 = new Triangle(b, h);
         cout << "Triangle created." << endl;
         s1->areaCalculate();
         s1->display();
         break;
      default:
         cout << "Invalid choice." << endl;
      }

      cout << "Enter your choice or -1 to quite: ";
      cin >> choice;
   }

   cout << "\t----GoodBye----\t" << endl
        << endl;

   return 0;
}