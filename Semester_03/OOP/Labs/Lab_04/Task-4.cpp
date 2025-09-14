#include <iostream>
using namespace std;
class Bracket{
private:
string equation;
public:
Bracket(string equ)
{
this-> equation = equ;
}
void setEqu(string equ)
{
this-> equation = equ;
}
string getEqu()
{
return equation;
}

bool isValid(string equ)
{
    int count=0;
    int count2 =0;
    int size = equ.size();
for(int i = 0 ; i < size; i++)
{
if( equ[i] == '(' )
{
    count++;
}
if( equ[i] == ')' )
{
    count2++;
}

}
if(count == count2)
{
    return true;
}
return false;
}
void display()
{
    cout << "Your Equation is: " << equation << endl;
}
};

int main()
{
    string equation;
    cout << "Enter an Equation: ";
    cin >> equation;

    Bracket obj(equation);

    obj.display();

    bool result = obj.isValid(equation);
    if(result != true)
    {
        cout << "Equation is Not valid" << endl;
    }
    else{
         cout << "Equation is valid" << endl;
    }
    
    return 0;
}
