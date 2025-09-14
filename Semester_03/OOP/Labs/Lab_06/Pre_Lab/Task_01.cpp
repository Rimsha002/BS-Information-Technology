#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    void setReal(int r)
    {
        real = r;
    }
    void setImag(int i)
    {
        imag = i;
    }
    friend Complex sum(Complex c1, Complex c2);
    friend void display(Complex c1, Complex c2, Complex c3);
};



// Declaration of friend function
Complex sum(Complex c1, Complex c2)
{
    Complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}
void display(Complex c1, Complex c2, Complex c3)
{
    cout << "First Complex Number: " << c1.real << " + " << c1.imag << "i" << endl;
    cout << "Second Complex Number: " << c2.real << " + " << c2.imag << "i" << endl;
    cout << "Result is: " << c3.real << " + " << c3.imag << "i" << endl << endl;
}



int main()
{
    Complex c1, c2, c3;
    int r1, r2;
    int i1, i2;
    cout << "\nEnter the first complex number: \n";
    cout << "Real part: ";
    cin >> r1;
    cout << "Imaginary part: ";
    cin >> i1;
    cout << "\nEnter the second complex number: \n";
    cout << "Real part: ";
    cin >> r2;
    cout << "Imaginary part: ";
    cin >> i2;

    c1.setReal(r1);
    c1.setImag(i1);
    c2.setReal(r2);
    c2.setImag(i2);

    c3 = sum(c1, c2);
    display(c1, c2, c3);

    
    return 0;
}
