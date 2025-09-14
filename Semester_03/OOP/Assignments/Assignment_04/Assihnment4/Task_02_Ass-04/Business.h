#ifndef BUSINESSACCOUNT_H
#define BUSINESSACCOUNT_H

#include "Account.h"
#include <vector>

class BusinessAccount : public Account
{
private:
    double negativeBalance;
    double totalTransactions;

public:
    // Constructors
    BusinessAccount();
    BusinessAccount(string accNum, Person holder, const char *initBalance, double negativeBalance);

    // Destructor
    ~BusinessAccount();

    // Setters
    void setNegativeBalance(double balance);
    double getNegativeBalance() const;

    // Overridden functions
    void display();
    void withdraw(const double amount) ;
    void deposit(const double amount);
    void transfer(const double amount, Account &toAccount) ;

    // Additional functionalities
    void clearNegativeBalance();
    void incrementNegativeBalance();
    void showNegativeBalance() const;
};

#endif
