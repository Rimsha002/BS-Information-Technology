#include <iostream>
#include <cstring>

using namespace std;

// OverLoading Function
class Fraction
{
    int nominator;
    int denominator;

    friend Fraction operator+(Fraction f1, Fraction f2);
    friend Fraction operator-(Fraction f1, Fraction f2);
    friend Fraction operator*(Fraction f1, Fraction f2);
    friend Fraction operator/(Fraction f1, Fraction f2);
    friend istream &operator>>(istream &i, Fraction f);
    friend ostream &operator<<(ostream &o, Fraction f);
    friend Fraction operator!(Fraction f1);
    friend Fraction operator~(Fraction f1);
    friend Fraction operator++(Fraction f1);
    friend Fraction operator--(Fraction f1);

public:
    Fraction(int n = 0, int d = 1) // Default + Paramaterize Constractor
    {
        bool validInput = false;
        while (!validInput)
        {
            try
            {
                if (d == 0 || d < 0)
                {
                    throw "Invalid denominator";
                }
                if (n < 0)
                {
                    throw "Invalid Nominator";
                }
                validInput = true;
            }
            catch (const char *msg)
            {
                cout << "Error! " << msg << endl;
                cout << "Please enter a valid ";
                if (strcmp(msg, "Invalid Nominator") == 0)
                {
                    cout << "nominator: ";
                    cin >> n;
                }
                else
                {
                    cout << "denominator: ";
                    cin >> d;
                }
            }
        }
        nominator = n;
        denominator = d;
    }

    // Copy Constractor
    Fraction &operator=(Fraction frac)
    {
        nominator = frac.nominator;
        denominator = frac.denominator;
        return *this;
    }

    // Display
    void display()
    {
        int small = nominator;
        if (denominator < small)
        {
            small = denominator;
        }

        if (nominator % denominator == 0 || denominator % nominator == 0)
        {
            nominator = double(nominator) / small;
            denominator = double(denominator) / small;
        }
        else
        {
            for (int i = 2; i <= small; i++)
            {
                while (nominator % i == 0 && denominator % i == 0)
                {
                    nominator /= i;
                    denominator /= i;
                }
            }
        }

        cout << nominator << " / " << denominator << endl;
    }
};

Fraction operator+(Fraction f1, Fraction f2)
{
    Fraction f3;
    int sum;
    f3.nominator = ((f1.nominator * f2.denominator) + (f1.denominator * f2.nominator));

    f3.denominator = (f1.denominator * f2.denominator);
    return f3;
}

Fraction operator-(Fraction f1, Fraction f2)
{
    Fraction f3;
    int sum;
    f3.nominator = ((f1.nominator * f2.denominator) - (f1.denominator * f2.nominator));

    f3.denominator = (f1.denominator * f2.denominator);
    return f3;
}

Fraction operator*(Fraction f1, Fraction f2)
{
    Fraction f3;
    f3.nominator = f1.nominator * f2.nominator;
    f3.denominator = f1.denominator * f2.denominator;
    return f3;
}

Fraction operator/(Fraction f1, Fraction f2)
{
    Fraction f3;
    int temp;
    temp = f2.nominator;
    f2.nominator = f2.denominator;
    f2.denominator = temp;

    f3.nominator = f1.nominator * f2.nominator;
    f3.denominator = f1.denominator * f2.denominator;
    return f3;
}

istream &operator>>(istream &i, Fraction f)
{
    cout << "Enter a nominator: ";
    i >> f.nominator;
    cout << "Enter a denominator: ";
    i >> f.denominator;
    return i;
}

ostream &operator<<(ostream &o, Fraction f)
{
    o << f.nominator << " / " << f.denominator;
    return o;
}

Fraction operator!(Fraction f1)
{
    f1.nominator = -1 * f1.nominator;
    f1.denominator = -1 * f1.denominator;
    return f1;
}

Fraction operator~(Fraction f1) // Inverse or invert fraction
{
    Fraction f3;
    f3.nominator = f1.denominator;
    f3.denominator = f1.nominator;
    return f3;
}

Fraction operator++(Fraction f1)
{
    f1.nominator = f1.nominator + 1;
    f1.denominator = f1.denominator + 1;
    return f1;
}

Fraction operator--(Fraction f1)
{
    f1.nominator = f1.nominator - 1;
    f1.denominator = f1.denominator - 1;
    return f1;
}

int main()
{
    int nominator;
    int denominator;
    cout << "Enter a nominator: ";
    cin >> nominator;
    cout << "Enter a denominator: ";
    cin >> denominator;

    Fraction f1(nominator, denominator);
    f1.display();

    // Copy
    cout << "\n--Copy Constractor--" << endl;

    Fraction f_Copy;
    f_Copy = f1;
    f_Copy.display();

    cout << "\nEnter 2nd fraction" << endl;
    int n2;
    int d2;
    cout << "Nominator: ";
    cin >> n2;
    cout << "Denominator: ";
    cin >> d2;

    Fraction f2(n2, d2);
    Fraction f3;
    f2.display();

    // Addition
    cout << "\n--Addition--\n\n";

    f3 = f1 + f2;
    cout << "Addition of " << f1 << " and " << f2 << " is:  ";
    f3.display();
    cout << endl;

    // Subtraction
    cout << "\n--Subtraction--\n\n";
    f3 = f1 - f2;
    cout << "Subtraction of " << f1 << " and " << f2 << " is:  ";
    f3.display();
    cout << endl;

    // Multiplication
    cout << "\n--Multiplication--\n\n";

    f3 = f1 * f2;
    cout << "Multiplication of " << f1 << " and " << f2 << " is:  ";
    f3.display();

    // Division
    cout << "\n--Division--\n\n";
    f3 = f1 / f2;
    cout << "Division of " << f1 << " and " << f2 << " is:  ";
    f3.display();

    // extraction (>>)
    cout << "\n--Extraction--\n\n";
    cin >> f1;
    cout << "Extraction done!" << endl;

    // insersion (<<)
    cout << "\n--Insersion--\n\n";
    cout << "Insersion of first fraction is:  " << f1 << endl;

    // Negation (!)
    cout << "\n--Negation--\n";
    f3 = !f1;
    cout << "Negation of " << f1 << " is:  " << f3 << endl;
    // as I overload insersion and extraction operator, So Iuse them instead of display

    // Invert (~)
    cout << "\n--Invert--\n\n";
    f3 = ~f1;
    cout << "Invert of " << f1 << " is:  " << f3 << endl;

    // Increment (++)
    cout << "\n--Increment--\n\n";
    f3 = ++f1;
    cout << "Increment of " << f1 << " is:  " << f3 << endl;

    // Decrement (--)
    cout << "\n--Decrement--\n\n";
         
    f3 = --f1;
    cout << "Decrement of " << f1 << " is:  " << f3 << endl;

    cout << endl;
    return 0;
}