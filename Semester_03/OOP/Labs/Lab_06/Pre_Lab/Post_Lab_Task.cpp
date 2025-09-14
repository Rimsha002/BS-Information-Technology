#include <iostream>
using namespace std;

class VicobaAccount
{
    int amountBorrowd;
    static int interestRate;
    int noOfYear;

public:
    // Constructor
    VicobaAccount(int loan = 0, int duration = 0, int interestR = 0)
    {
        amountBorrowd = loan;
        noOfYear = duration;
        interestRate = interestR;
    }
    // Getter Setter
    void setLoan(int loan)
    {
        amountBorrowd = loan;
    }
    int getLoan()
    {
        return amountBorrowd;
    }
    void setDuration(int duration)
    {
        noOfYear = duration;
    }
    int getDuration()
    {
        return noOfYear;
    }

    // Static Function to alter annual intrest
    static void setAlterInterest(int interestR)
    {
        interestRate = interestR;
    }

    // Getter of Total intrest
    int getTotalInterst()
    {
        int totalInterest = interestRate * noOfYear;
        return totalInterest;
    }

    // Total Repay amount
    int moneyRepay()
    {
        int intrestpay = getTotalInterst();
        amountBorrowd = amountBorrowd + intrestpay;
        return amountBorrowd;
    }
};

int VicobaAccount::interestRate = 5;

int main()
{
    int loan;
    int duration;
    int intrestRate;

    cout << "Enter the loan amount: ";
    cin >> loan;
    cout << "Enter the duration of the loan: ";
    cin >> duration;
    cout << "Enter the interest rate: ";
    cin >> intrestRate;

    VicobaAccount vicobaA(loan, duration, intrestRate);


    cout << "The total interest is: " << vicobaA.getTotalInterst() << endl;
    cout << "The total amount to be repaid is: " << vicobaA.moneyRepay() << endl;

    return 0;
}
