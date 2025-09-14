#include <iostream>
#include <vector>
using namespace std;

class Person
{
    static int id;
    string name;
    string address;
    char gender;
    int noOfAccount;

public:
    Person()
    {
        id++;
        name = "";
        address = "";
        gender = 'M';
        noOfAccount = 0;
    }
    Person(string n, string address, char g, int noOfA)
    {
        id++;
        name = n;
        address = address;
        gender = g;
        noOfAccount = noOfA;
    }
};
int Person::id = 0;

// Account
class Account
{
    static int accountNo;
    int currentBalance;
    Person person;

public:
    Account()
    {
        accountNo++;
        currentBalance = 0;
    }
    Account(int currentB, Person person)
    {
        accountNo++;
        this->currentBalance = currentB;
    }

    void deposite(int amount)
    {
        currentBalance = currentBalance + amount;
        cout << "Deposit Successfully" << endl;
    }

    void withDraw(int amount)
    {
        currentBalance = currentBalance - amount;
        cout << amount << " withdraw Successfully" << endl;
    }

    void setCurrBalance(int b)
    {
        currentBalance = b;
    }

    int getBalance()
    {
        return currentBalance;
    }
};
int Account::accountNo = 0;

// Saving Account
class SavingA : public Account
{
    int intrest;
    int timeLimit;

public:
    SavingA() : Account()
    {
        intrest = 0;
        timeLimit = 0;
    }
    SavingA(int intrest, int time, int currentB, Person person) : Account(currentB, person)
    {
        intrest = 0;
        timeLimit = 0;
    }

    void withdraw(int amount)
    {
        int currentBalance = getBalance();
        int mini = currentBalance * (10 / 100);
        if ((currentBalance - amount) <= mini)
        {
            cout << "Sorry! Not allow to withdraw \n Mini balance required is " << mini << endl;
        }
        if ((currentBalance - amount) > mini)
        {
            currentBalance = currentBalance - amount;
            setCurrBalance(currentBalance);
        }
    }

    void intrestCal()
    {

        int currentBalance = getBalance();
        intrest = intrest * timeLimit * currentBalance;
        int TotalB = intrest + currentBalance;
        setCurrBalance(TotalB);
    }

    void display()
    {
        cout << "Interest : "<< intrest << endl;
        cout << "Time Limit : "<< timeLimit << endl;
        // Person p.display();

    }
};

// Checking Account
class CheckingA : public Account
{
    int overdraft_Limit;

public:
    CheckingA() : Account()
    {
        overdraft_Limit = 0;
    }
    CheckingA(int limit,int currentB, Person person) : Account(currentB, person)
    {
        overdraft_Limit = limit;
    }

    void withdraw(int amount)
    {
        int currentBalance = getBalance();
        int mini = currentBalance * (10 / 100);
        if ((currentBalance - amount) <= mini)
        {
            cout << "Sorry! Not allow to withdraw \n Mini balance required is " << mini << endl;
        }
        if ((currentBalance - amount) > mini)
        {
            currentBalance = currentBalance - amount;
            setCurrBalance(currentBalance);
            cout << "Amount Withdraw Successfully" << endl;
        }
    }

    void feeDeduction(int feeamount)
    {
        int currentBalance = getBalance();

        if ((currentBalance - feeamount) < 0)
        {
            cout << "Sorry! Your Balance is low to deduct fee " << endl;
        }
        if ((currentBalance - feeamount) > 0)
        {
            currentBalance = currentBalance - feeamount;
            setCurrBalance(currentBalance);
            cout << "Fee Deducted Successfully" << endl;
        }
    }
};

// Loan Account
class LoanA : public Account
{
    int intrest_rate;
    int term;

public:
    LoanA() : Account()
    {
        intrest_rate = 0;
        term = 0;
    }
    LoanA(int intrest_R, int term,int currentB, Person person) : Account(currentB, person)
    {
        this->intrest_rate = intrest_R;
        this->term = term;
    }

    void Addintrest()
    {

        int currentBalance = getBalance();
        int intrest = intrest_rate * term * currentBalance;
        int TotalB = intrest + currentBalance;
        setCurrBalance(TotalB);
        cout << "Intrest added Successfully" << endl;
        int newBalance = getBalance();
        cout << "New Balance is: " << newBalance << endl;
    }
};

class Bank : Person, Account
{
    public:
    Bank() : Person(), Account() {}

    vector<Person> Customer;
    vector<SavingA> SavingA;
    vector<CheckingA> CheckingA;
    vector<LoanA> LoanA;
    int noOfA;

    void addCustomer()
    {
        string n;
        string address;
        char g;

        cout << "Enter name of customer: ";
        cin >> n;
        cout << "Enter Address of customer: ";
        cin >> address;
        cout << "Enter Gender of customer: ";
        cin >> g;
        cout << "Enter No of Accounts for customer: ";
        cin >> noOfA;

       static Person customer(n, address, g, noOfA);
        Customer.push_back(customer);

    }
    void createAccount()
    {
        cout << "Which accout you want to create: \n 1- Saving Accout \n 2- Checking Accout \n 1- Loan Accout \n Enter choice: "
             << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        if(choice == 1)
        {
            int intrest;
            int time;
            int currentB;

            cout << "Enter intrest Rate: ";
            cin >> intrest;
            cout << "Enter time limit of interest: ";
            cin >> time;
            cout << "Enter Current Balance of your account: ";
            cin >> currentB;
            
            // Person p = Customer[0];
            SavingA sav(intrest, time, currentB, Customer[0]);

             break;
        }
        case 2:
        {
             int overdraft;

            cout << "Enter Overdraft Limit: ";
            cin >> overdraft;
                        
            Person p = Customer[0];
            // SavingA(intrest, time, currentB, customer);
            break;
        }
        case 3:
        {
             int intrest;
            int term;
            

            cout << "Enter intrest Rate: ";
            cin >> intrest;
            cout << "Enter term limit of interest: ";
            cin >> term;
            
            
            Person p = Customer[0];
            // SavingA(intrest, time, currentB, customer);
            break;
        }
        }
    }

    void display()
    {

    }
    vector<Account> accounts;
};

int main()
{
    Bank bank;
    bank.addCustomer();
    bank.createAccount();

    return 0;
}