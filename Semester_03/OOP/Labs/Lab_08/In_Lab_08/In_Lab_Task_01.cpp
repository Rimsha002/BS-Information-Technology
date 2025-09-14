#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Polinomial
{
    int *coffi = new int;
    int size;
    int *power = new int;

public:
    Polinomial()
    {
        power = nullptr;
        coffi = nullptr;
        size = 0;
    }
    Polinomial(int s)
    {
        this->size = s;
        coffi = new int[size];
        power = new int[size];
        for (int i = 0; i < size; ++i)
        {
            coffi[i] = 0;
            power[i] = i;
        }
    }

    // Input
    void input()
    {
        cout << "Enter Cofficients: ";

        for (int i = size - 1; i >= 0; i--)
        {
            power[i] = i;
            cin >> coffi[i];
        }
    }

    // copy Constructor
    Polinomial(Polinomial &poli)
    {
        poli.size = size;
        for (int i = 0; i < size; i++)
        {
            coffi[i] = poli.coffi[i];
        }
        for (int i = 0; i < size; i++)
        {
            cout << this->coffi[i] << " ";
        }
    }

    // display
    int display()
    {
        cout << "Your Polynomial is: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << coffi[i] << "x^" << power[i] << " ";
        }
        cout << endl
             << endl;
    }
    // Get Degree
    int getDegree()
    {
        return size - 1;
    }
    // set Cofficient
    void setCofficient(int degree, int coffi)
    {
        for (int i = 0; i < size; i++)
        {
            if (degree >= 0 && degree < size)
            {
                this->coffi[degree] = coffi;
            }
            else
            {
                cout << "degree out of rang";
            }
        }
        display();
    }

    // evalute
    void evalute(double x)
    {
        double result = 0;
        for (int i = 0; i < size; i++)
        {
            result += coffi[i] * pow(x, power[i]);
        }
        cout << "Result is: " << result << endl;
    }

    // Addition
    Polinomial sum(Polinomial &poli)
    {

        Polinomial poli2(size);

        for (int i = 0; i < size; i++)
        {
            poli2.coffi[i] = poli.coffi[i] + coffi[i];
        }
        return poli2;
    }
    // Subtraction
    Polinomial subtraction(Polinomial &poli)
    {
        Polinomial poli2(size);

        for (int i = 0; i < size; i++)
        {
            poli2.coffi[i] = poli.coffi[i] - coffi[i];
        }
        return poli2;
    }
    // Multiplication
    Polinomial multiplication(Polinomial &poli)
    {
        Polinomial poli2(size);

        for (int i = 0; i < size; i++)
        {
            poli2.coffi[i] = poli.coffi[i] * coffi[i];
        }
        return poli2;
    }

    // Overloading
    Polinomial &operator+(const Polinomial &poli)
    {
        size = poli.size;

        for (int i = 0; i < size; i++)
        {
            coffi[i] += poli.coffi[i];
        }

        return *this;
    }

    Polinomial &operator-(const Polinomial &poli)
    {
        size = poli.size;
        for (int i = 0; i < size; i++)
        {
            coffi[i] -= poli.coffi[i];
        }

        return *this;
    }
    Polinomial &operator*(const Polinomial &poli)
    {

        size = poli.size;
        for (int i = 0; i < size; i++)
        {
            coffi[i] += poli.coffi[i];
        }

        return *this;
    }

    Polinomial &operator=(const Polinomial &poli)
    {
        size = poli.size;
        for (int i = 0; i < size; i++)
        {
            coffi[i] = poli.coffi[i];
        }

        return *this;
    }

    // Comparison Operator
    bool operator==(const Polinomial &poli)
    {
        for (int i = 0; i < size; i++)
        {
            if (coffi[i] != poli.coffi[i])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    // Index operator
    int index(int x)
    {
        for (int i = 0; i < size; i++)
        {
            if (i == x)
            {
                return coffi[i];
            }
        }
    }

    // Casting  operator
    vector<int> operator()()
    {
        vector<int> v;
        for (int i = 0; i < size; i++)
        {
            int element = coffi[i];
            v.push_back(element);
        }
        return v;
    }

    friend istream &operator>>(istream &i, Polinomial poli);
    friend ostream &operator<<(ostream &o, Polinomial poli);

    ~Polinomial()
    {
        delete[] coffi;
    }
};

istream &operator>>(istream &in, Polinomial poli)
{

    for (int i = poli.size - 1; i >= 0; i--)
    {
        in >> poli.coffi[i];
    }
}
ostream &operator<<(ostream &o, const Polinomial poli)
{
    for (int i = 0; i < poli.size; i++)
    {
        o << poli.coffi[i] << "x^" << poli.power[i] << " ";
    }
}

int main()
{
    int size;
    cout << "Enter size of Polynomial: ";
    cin >> size;

    Polinomial poli(size);
    poli.input(); // Input
    poli.display();

    int choice;
    do
    {
        cout << "Select the option or -1 to terminate" << endl;
        cout << "1. Get Degree" << endl;
        cout << "2. Set Cofficient" << endl;
        cout << "3. evalute(double x)" << endl;
        cout << "4. Sum" << endl;
        cout << "5. Subtraction" << endl;
        cout << "6. Multiplication" << endl;
        cout << "7. Overloading( + , - , *, =)" << endl;
        cout << "8. Comparison Operator( == )" << endl;
        cout << "9. Indexing Operator" << endl;
        cout << "10. Casting Operator(Vector)" << endl;
        cout << "11. Stream Operator" << endl;
        cout << "12. Exit or press -1" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

       if (choice == -1) {
            break;
        }

        switch (choice)
        {
        case 1:
        {
            cout << "\n---Get degree" << endl;
            int d = poli.getDegree();
            cout << d << endl;
            break;
        }
        case 2:
        {
            cout << "---Set Cofficient" << endl;
            int deg, c;
            cout << "Enter degree for cofficient: ";
            cin >> deg;
            cout << "Enter new cofficient: ";
            cin >> c;
            poli.setCofficient(deg, c);
            break;
        }
        case 3:
        {
            cout << "---Evalute" << endl;
            double x;
            cout << "Enter value of x: ";
            cin >> x;
            poli.evalute(x);
            break;
        }
        case 4:
        {
            cout << "---Sum" << endl;
            Polinomial poli2(size);
            poli2.input();
            poli2.display();
            Polinomial poli3;
            poli3 = poli2.sum(poli);
            poli3.display();
            break;
        }
        case 5:
        {
            cout << "---Subtraction" << endl;
            Polinomial poli2(size);
            poli2.input();
            poli2.display();
            Polinomial poli3;
            poli3 = poli2.subtraction(poli);
            poli3.display();
            break;
        }

        case 6:
        {
            cout << "---Multiplication" << endl;
            Polinomial poli2(size);
            poli2.input();
            poli2.display();
            Polinomial poli3;
            poli3 = poli2.multiplication(poli);
            poli3.display();
            break;
        }

        case 7:
        {
            cout << "---Overloading" << endl;
            cout << " +  operator" << endl;
            Polinomial poli2(size);
            poli2.input();
            poli2.display();
            Polinomial poli3;
            poli3 = (poli2 + poli);
            poli3.display();

            cout << " -  operator" << endl;
            poli3 = (poli2 - poli);
            poli3.display();

            cout << " *  operator" << endl;
            poli3 = (poli2 * poli);
            poli3.display();

            cout << " =  operator" << endl;
            poli3 = poli2;
            poli3.display();
            break;
        }

        case 8:
        {
            cout << "---Comparison Operator" << endl;
            Polinomial poli2(size);
            poli2.input();
            poli2.display();
            if (poli == poli2)
            {
                cout << "Both are equal" << endl;
            }
            else
            {
                cout << "Both are not equal" << endl;
            }
            break;
        }

        case 9:
        {
            cout << "---Indexing" << endl;
            cout << "Enter index: ";
            int idx;
            cin >> idx;
            int result;
            result = poli.index(idx);
            cout << "Cofficient at that index is: " << result << endl;
            break;
        }

        case 10:
        {
            cout << "---Casting Operator(Vector)" << endl;
            vector<int> v;
            v = poli();
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            break;
        }

        case 11:
        {
            cout << "---Stream Operator" << endl;
            cin >> poli;
            cout << poli;
            break;
        }
        case 12:
        {
            choice = -1;
            cout << "Exiting..." << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
      
    }while(choice != -1);

    return 0;
}
