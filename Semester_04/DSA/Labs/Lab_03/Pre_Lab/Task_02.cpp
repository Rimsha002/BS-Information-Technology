#include <iostream>
#include <math.h>

using namespace std;

// Polynomial ADT

class Polynomial
{
public:
    Polynomial(int max_degree);
    Polynomial(const Polynomial &obj);
    int get_degree() const;
    Polynomial &operator=(const Polynomial &other);
    void add_term(int coefficient, int degree);
    void remove_term(int degree);
    void set_coeffecient(int coefficient, int degree);
    friend ostream &operator<<(ostream &os, const Polynomial &poly);
    double operator()(double x) const;
    Polynomial operator+(const Polynomial &other);
    Polynomial operator*(const Polynomial &other);
    ~Polynomial();

private:
    int *coefficients;
    int max_degree;
};

Polynomial::Polynomial(int max_degree)
{
    this->max_degree = max_degree;
    coefficients = new int[max_degree + 1];
    for (int i = 0; i <= max_degree; i++)
    {
        coefficients[i] = 0;
    }
}

Polynomial::Polynomial(const Polynomial &obj)
{
    max_degree = obj.max_degree;
    coefficients = new int[max_degree + 1];
    for (int i = 0; i <= max_degree; i++)
    {
        coefficients[i] = obj.coefficients[i];
    }
}

int Polynomial::get_degree() const
{
    return max_degree;
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this != &other)
    {
        delete[] coefficients;
        max_degree = other.max_degree;
        coefficients = new int[max_degree + 1];
        for (int i = 0; i <= max_degree; i++)
        {
            coefficients[i] = other.coefficients[i];
        }
    }
    return *this;
}

void Polynomial::add_term(int coefficient, int degree)
{
    if (degree <= max_degree)
    {
        coefficients[degree] += coefficient;
    }
}

void Polynomial::remove_term(int degree)
{
    if (degree <= max_degree)
    {
        coefficients[degree] = 0;
    }
}

void Polynomial::set_coeffecient(int coefficient, int degree)
{
    if (degree <= max_degree)
    {
        coefficients[degree] = coefficient;
    }
}

ostream &operator<<(ostream &os, const Polynomial &poly)
{
    for (int i = poly.max_degree; i >= 0; i--)
    {
        if (poly.coefficients[i] != 0)
        {
            if (i == 0)
            {
                os << poly.coefficients[i];
            }
            else if (i == 1)
            {
                os << poly.coefficients[i] << "x + ";
            }
            else
            {
                os << poly.coefficients[i] << "x^" << i << " + ";
            }
        }
    }

    return os;
}

double Polynomial::operator()(double x) const
{
    double result = 0;
    for (int i = 0; i <= max_degree; i++)
    {
        result += coefficients[i] * pow(x, i);
    }

    return result;
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    int new_max_degree = max_degree > other.max_degree ? max_degree : other.max_degree;
    Polynomial result(new_max_degree);
    for (int i = 0; i <= new_max_degree; i++)
    {
        result.coefficients[i] = coefficients[i] + other.coefficients[i];
    }

    return result;
}

Polynomial Polynomial::operator*(const Polynomial &other)
{
    int new_max_degree = max_degree + other.max_degree;
    Polynomial result(new_max_degree);

    for (int i = 0; i <= max_degree; i++)
    {
        for (int j = 0; j <= other.max_degree; j++)
        {
            result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return result;
}

Polynomial::~Polynomial()
{
    delete[] coefficients;
}

int main()
{
    //Menu base program
    int max_degree;
    cout << "Enter the maximum degree of the polynomial: ";
    cin >> max_degree;
    Polynomial poly1(max_degree);
    Polynomial poly2(max_degree);
    Polynomial result(max_degree);

    int choice;

    do
    {
        cout << "1. Add term to polynomial 1" << endl;
        cout << "2. Add term to polynomial 2" << endl;
        cout << "3. Remove term from polynomial 1" << endl;
        cout << "4. Remove term from polynomial 2" << endl;
        cout << "5. Set coefficient of polynomial 1" << endl;
        cout << "6. Set coefficient of polynomial 2" << endl;
        cout << "7. Display polynomial 1" << endl;
        cout << "8. Display polynomial 2" << endl;
        cout << "9. Evaluate polynomial 1" << endl;
        cout << "10. Evaluate polynomial 2" << endl;
        cout << "11. Add two polynomials" << endl;
        cout << "12. Multiply two polynomials" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int coefficient, degree;
            cout << "Enter coefficient: ";
            cin >> coefficient;
            cout << "Enter degree: ";
            cin >> degree;
            poly1.add_term(coefficient, degree);
            break;
        case 2:
            cout << "Enter coefficient: ";
            cin >> coefficient;
            cout << "Enter degree: ";
            cin >> degree;
            poly2.add_term(coefficient, degree);
            break;
        case 3:
            cout << "Enter degree: ";
            cin >> degree;
            poly1.remove_term(degree);
            break;
        case 4:
            cout << "Enter degree: ";
            cin >> degree;
            poly2.remove_term(degree);
            break;
        case 5:
            cout << "Enter coefficient: ";
            cin >> coefficient;
            cout << "Enter degree: ";
            cin >> degree;
            poly1.set_coeffecient(coefficient, degree);
            break;
        case 6:
            cout << "Enter coefficient: ";
            cin >> coefficient;
            cout << "Enter degree: ";
            cin >> degree;
            poly2.set_coeffecient(coefficient, degree);
            break;
        case 7:
            cout << poly1 << endl;
            break;
        case 8:
            cout << poly2 << endl;
            break;
        case 9:
            double x;
            cout << "Enter x: ";
            cin >> x;
            cout << poly1(x) << endl;
            break;
        case 10:
            cout << "Enter x: ";
            cin >> x;
            cout << poly2(x) << endl;
            break;
        case 11:
            result = poly1 + poly2;
            cout << result << endl;
            break;

        case 12:
            result = poly1 * poly2;
            cout << result << endl;
            break;
        case 13:
            break;
        default:

            cout << "Invalid choice" << endl;
        }
    } while (choice != 13);

    cout << "\tGoodBye!" << endl;
    return 0;
}