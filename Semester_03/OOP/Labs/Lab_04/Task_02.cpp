#include <iostream>
using namespace std;

class Rational
{
private:
    int numenator;
    int denomenator;
    int numenator2;
    int denomenator2;

public:
    Rational(int nomen = 0, int denomen = 0, int nomen2 = 0, int denomen2 = 0)
    {
        this->numenator = nomen;
        this->denomenator = denomen;
        this->numenator2 = nomen2;
        this->denomenator2 = denomen2;
    }
    // Rational(int nomen = 0, int denomen = 0)
    // {
    //     this->numenator = nomen;
    //     this->denomenator = denomen;
    // }
    void setNomen(int nomen)
    {
        this->numenator = nomen;
    }
    void setDenomen(int denomen)
    {
        this->denomenator = denomen;
    }
    const int getNomen()
    {
        return numenator;
    }
    const int getDenomen()
    {
        return denomenator;
    }
    // const int multiply(Rational &other)
    const int multiply()
    {
    //     int result = numenator * other.getNomen();
    //     int result2 = denomenator * other.getDenomen();
    int result = numenator * numenator2;
        int result2 = denomenator * denomenator2;
        // Rational rational1(result,result2);
        // return rational1;

        cout << "\n Multiplication is : " << result << " / " << result2 << endl;
    }
    const int reduced()
    {
        int greator;
        int num;
        if (numenator > denomenator)
        {
            greator = numenator;
        }
        else
        {
            greator = denomenator;
        }

        for (int i = 2; i < greator; i++)
        {
            if ((numenator / i) && (denomenator / i))
            {
                num = i;
                break;
            }
        }
        int quot1 = numenator / num;
        int quot2 = denomenator / num;

        cout << "\n Reduced Form is : " << quot1 << " / " << quot2 << endl;
    }
};
int main()
{
    int choice;
    int numen1, numen2, denomen1, denomen2;
    cout << "What you want ?" << endl;
    cout << "1- Multiplication" << endl;
    cout << "2- Reduction" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {

        cout << "\n--Enter 1 st Rational number data--" << endl;
        cout << "Enter Numenator: ";
        cin >> numen1;
        cout << "Enter Denomenator: ";
        cin >> denomen1;

        cout << "\n--Enter 2nd Rational number data-- " << endl;
        cout << "Enter Numenator: ";
        cin >> numen2;
        cout << "Enter Denomenator: ";
        cin >> denomen2;

        Rational obj(numen1, denomen1, numen2, denomen2);
        obj.multiply();
        break;
    }
    case 2:
    {

    cout << "\n--Enter 1 st Rational number data--" << endl;
    cout << "Enter Numenator: ";
    cin >> numen1;
    cout << "Enter Denomenator: ";
    cin >> denomen1;

    Rational obj1(numen1, denomen1, 0,0);
    obj1.reduced();

    break;
    }
    }
    return 0;
}





























    // Rational add2(13, 3);
    // int result = obj1.multiply(add2);
    // cout << result << endl;