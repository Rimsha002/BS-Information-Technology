#include <iostream>
using namespace std;

// Forward Declaration
class Complex;

class Calculator
{
public:
    int sumRealNumber(Complex, Complex);
};

class Complex
{
    int a;
    int b;
    // Indiviually Declaring friend function
    friend int Calculator ::sumRealNumber(Complex, Complex);

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

};

int Calculator :: sumRealNumber(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);
    Calculator calc;
    int result = calc.sumRealNumber(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << result << endl;
    return 0;
}