#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
#include "Person.h" 

using namespace std;

class Account {

protected:
    string accountNumber;
    Person accountHolder;
    char balance[100];  
    vector<Transaction> transactions;

public:
    // Constructors
    Account();
    Account(string accNum, Person holder, const char* initBalance);
    Account(const Account &acc);

    // Destructor
    virtual ~Account();

    // Setters
    void setAccountNumber(const string &accNum);
    void setAccountHolder(const Person &holder);
    void setBalance(const char* newBalance);

    // Getters
    string getAccountNumber() const;
    Person getAccountHolder() const;
    const char* getBalance() const;

    // Methods
    void checkBalance() const;
    void viewTransactionHistory() const;

    // Pure virtual functions
    virtual void display() const = 0;
    virtual void withdraw(const double amount) = 0;
    virtual void deposit(const double amount) = 0;
    virtual void transfer(const double amount, Account &toAccount) = 0;
};

#endif // ACCOUNT_H
