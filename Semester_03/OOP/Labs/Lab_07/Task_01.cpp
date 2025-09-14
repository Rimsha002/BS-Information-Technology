#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
   int real;
   int img;

public:
   Complex(double r = 0, double i = 0)
   {
      real = r;
      img = i;
   }

   void setReal(int r)
   {
      real = r;
   }

   void setImg(int i)
   {
      img = i;
   }

   double getReal()
   {
      return real;
   }

   double getImaginary()
   {
      return img;
   }

   void display()
   {
      cout << real << " + " << img << "i";
   }

   Complex operator+(Complex c1)
   {
      cout << "\n---1--- Sum of two complex numbers: ";
      Complex c2;
      c2.real = real + c1.real;
      c2.img = img + c1.img;

      return c2;
   }
   Complex operator-(Complex c1)
   {
      cout << "\n---2--- Subtraction of two complex numbers: ";
      Complex c2;
      c2.real = real - c1.real;
      c2.img = img - c1.img;
      // c2.display();
      return c2;
   }

   Complex operator*(Complex c1)
   {
      cout << "\n---3--- Multiplication of two complex numbers: ";
      Complex c2;
      c2.real = real * c1.real;
      c2.img = img * c1.img;
      // c2.display();
      return c2;
   }

   Complex operator/(Complex c1)
   {
      cout << "\n---4--- Division of two complex numbers: ";
      Complex c2;
      if (real > c1.real && img > c1.img)
      {
         c2.real = real / c1.real;
         c2.img = img / c1.img;
      }
      else
      {
         c2.real = c1.real / real;
         c2.img = c1.img / img;
      }

      // c2.display();
      return c2;
   }

   // Assignment
   Complex &operator=(Complex c1)
   {
      real = c1.real;
      img = c1.img;

      return *this;
   }

   friend istream &operator>>(istream &i, Complex c1);
   friend ostream &operator<<(ostream &o, Complex c1);
   friend bool operator==(Complex c1, Complex c2);
   friend bool operator!=(Complex c1, Complex c2);
   friend bool operator>=(Complex c1, Complex c2);
   friend bool operator<=(Complex c1, Complex c2);
   friend Complex operator++(Complex c1);
   friend Complex operator--(Complex c1);
   friend int operator~(Complex c1);
   friend Complex operator!(Complex c1);
};
/////Ouside of Class
istream &operator>>(istream &i, Complex c1)
{
   i >> c1.real;
   i >> c1.img;
};

ostream &operator<<(ostream &o, Complex c1)
{
   o << c1.real << " + " << c1.img << "i";
}

bool operator==(Complex c1, Complex c2)
{
   if (c1.real == c2.real && c1.img == c2.img)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool operator!=(Complex c1, Complex c2)
{
   if (c1.real != c2.real && c1.img != c2.img)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool operator>=(Complex c1, Complex c2)
{
   int sum1;
   int sum2;
   sum1 = pow((pow(c1.real, 2) + pow(c1.img, 2)), 1 / 2);
   sum2 = pow((pow(c2.real, 2) + pow(c2.img, 2)), 1 / 2);
   if (sum1 > sum2)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool operator<=(Complex c1, Complex c2)
{
   int sum1;
   int sum2;
   sum1 = pow((pow(c1.real, 2) + pow(c1.img, 2)), 1 / 2);
   sum2 = pow((pow(c2.real, 2) + pow(c2.img, 2)), 1 / 2);
   if (sum1 < sum2)
   {
      return true;
   }
   else
   {
      return false;
   }
}

Complex operator++(Complex c1)
{
   c1.real++;
   c1.img++;
   return c1;
}

Complex operator--(Complex c1)
{
   c1.real--;
   c1.img--;
   return c1;
}

int operator~(Complex c1)
{
   int sum;

   sum = pow((pow(c1.real, 2) + pow(c1.img, 2)), 1 / 2);
   return sum;
}

Complex operator!(Complex c1)
{
   c1.real = -1 * c1.real;
   c1.img = -1 * c1.img;
   return c1;
}

///////////Main Part
int main()
{
   int r, i;
   int r2, i2;

   cout << "--1st Complex Number--" << endl;
   cout << "Enter real Part: ";
   cin >> r;
   cout << "Enter imaginary Part: ";
   cin >> i;

   Complex c1(r, i);
   c1.display();

   cout << "\n--2nd Complex Number--\n"
        << endl;
   cout << "Enter real Part: ";
   cin >> r2;
   cout << "Enter imaginary Part: ";
   cin >> i2;
   Complex c2(r2, i2);
   c2.display();

   Complex c3;

   c3 = c1 + c2;
   c3.display();

   c3 = c1 - c2;
   c3.display();

   c3 = c1 * c2;
   c3.display();

   c3 = c1 / c2;
   c3.display();

   // // Insertion Operator
   cout << "\n---5--- Insertion : ";
   // int in;
   // cin >> in;

   // // Extraction Operator
   cout << "\n---6--- Extraction: ";
   // int o;
   // cout << o;

   // Equality
   cout << "\n---7--- Equality: ";
   if (c1 == c2)
   {
      cout << "Both are equal" << endl;
   }
   else
   {
      cout << "Not Equal" << endl;
   }
   // Non Equality
   cout << "\n---8--- Non_Equality: ";
   if (c1 != c2)
   {
      cout << "True" << endl;
   }
   else
   {
      cout << "False" << endl;
   }
   // Absolute sum c1 > c2
   cout << "\n---9--- Absolute Sum1 > Sum2? : ";
   if (c1 >= c2)
   {
      cout << "Absolute sum of 1st Complex in greater or Equal" << endl;
   }
   else
   {
      cout << "False " << endl;
   }
   // Absolute sum c1 < c2
   cout << "\n---10--- Absolyte Sum S1 < S2? : ";
   if (c1 <= c2)
   {
      cout << "Absolute sum of 1st Complex in Lesser or Equal" << endl;
   }
   else
   {
      cout << "False " << endl;
   }

   // Assignment
   cout << "\n---11--- Assignment: ";
   c1 = c2;
   c1.display();

   // Increment
   cout << "\n---12--- Increment : ";
   cout << "\nOriginal No:";
   c1.display();

   c3 = ++c1;
   cout << "\nUpdate: ";
   c3.display();

   // Decrement
   cout << "\n---13--- Decrement : ";
   cout << "\nOriginal No :";
   c1.display();
   c3 = --c1;
   cout << "\nUpdated: ";
   c3.display();

   // Absolute sum
   cout << "\n---14--- Absolute sum: ";
   cout << ~c1;

   // inverse
   cout << "\n---15--- Inverse: ";
   cout << !c1;

   return 0;
}
