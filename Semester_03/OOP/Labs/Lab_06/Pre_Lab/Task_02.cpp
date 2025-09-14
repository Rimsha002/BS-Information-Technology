#include <iostream>
#include <vector>

using namespace std;

class PrimeSum
{
    int num;
    vector<int> v;

public:
    PrimeSum(int n)
    {
        this->num = n;
    }

    void Prime(int num)
    {
        for (int n = 2; n <= num; n++)
        {
            bool isPrime = true;
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                v.push_back(n);
            }
        }
    }
    
    vector<int> getV()
    {
        return v;
    }

    // void display()+
    // {
    //     for (int i = 0; i < v.size(); i++)
    //     {
    //         cout << v[i] << " ";
    //     }
    // }

    

    friend void primepairs(PrimeSum ps);
};

void primepairs(PrimeSum ps)
{
    vector<int> v = ps.getV(); 

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] + v[j] == ps.num)
            {
                cout << ps.num << " = " << v[i] << " " << v[j] << endl;
            }
        }
    }
}

int main()
{
    cout << "\t ----Prime Sum---- \n";
    int num;

    cout << "Enter a number: ";
    cin >> num;

    PrimeSum primesum(num);
    primesum.Prime(num);
   
    primepairs(primesum); 

    return 0;
}