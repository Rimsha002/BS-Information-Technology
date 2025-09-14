#include <iostream>
#include <exception>
using namespace std;
class Rational
{
    int numerator;
    int denominator;

public:
    Rational(int numerator = 0, int deno = 1)
    {
        try
        {
            if (deno == 0)
                throw runtime_error("Denominator must be non-zero");
            this->numerator = numerator;
            this->denominator = deno;
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    Rational Add(Rational second)
    {
        int sum_denominator = 0.0;
        if (this->denominator == second.denominator)
        {
            sum_denominator = this->denominator;
        }
        else
        {
            sum_denominator = this->denominator * second.denominator;
        }

        int sum_numerator = ((sum_denominator / this->denominator) * this->numerator) + ((sum_denominator / second.denominator) * second.numerator);

        Rational sum(sum_numerator, sum_denominator);
        return sum;
    }
    Rational Subtract(Rational second)
    {
        int subtract_denominator = 0.0;
        if (this->denominator == second.denominator)
        {
            subtract_denominator = this->denominator;
        }
        else
        {
            subtract_denominator = this->denominator * second.denominator;
        }

        int subtract_numerator = ((subtract_denominator / this->denominator) * this->numerator) - ((subtract_denominator / second.denominator) * second.numerator);
        Rational substract(subtract_numerator, subtract_denominator);
        return substract;
    }

    Rational Multiply(Rational second)
    {
        int multiply_denominator = this->denominator * second.denominator;

        int multiply_numerator = this->numerator * second.numerator;
        Rational substract(multiply_numerator, multiply_denominator);
        return substract;
    }

    void display()
    {
        int num = numerator;
        int deno = denominator;
        bool flag_one = false;
        bool flag_two = false;

        if (num < 0)
        {
            num *= -1;
            flag_one = true;
        }
        if (deno < 0)
        {
            deno *= -1;
            flag_two = true;
        }
        int minimum = num > deno ? deno : num;
        int HCF = 1;
        for (int i = 2; i <= minimum; i++)
        {
            if (num % i == 0 && deno % i == 0 && HCF < i)
            {
                HCF = i;
            }
        }
        if (flag_one)
        {
            num *= -1;
        }
        if (flag_two)
        {
            deno *= -1;
        }
        cout << "num: " << num / HCF << endl;
        cout << "Denomerator: " << deno / HCF << endl;
    }
};
int main()
{
    Rational one(12, 6);
    Rational two(5, 6);
    Rational sum;
    sum = one.Add(two);
    cout << "Sum: " << endl;
    sum.display();
    Rational subtract;
    subtract = one.Subtract(two);
    cout << "Subtract: " << endl;
    subtract.display();

    cout<<"Multiply: " << endl;
    Rational multiply;
    multiply = one.Multiply(two);
    multiply.display();
    return 0;
}
