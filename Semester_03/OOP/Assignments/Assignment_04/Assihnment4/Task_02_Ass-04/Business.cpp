#include "Business.h"
#include "Transaction.h"
#include <iostream>

using namespace std;

// Constructors
BusinessAccount::BusinessAccount() : Account()
{
    negativeBalance = 0.0;
    totalTransactions = 0.0;

}

BusinessAccount::BusinessAccount(string accNum, Person holder, const char* initBalance, double negativeBalance)
    : Account(accNum, holder, initBalance)
    {
        this->negativeBalance = negativeBalance;
        totalTransactions = 0.0;
    }

// Destructor
BusinessAccount::~BusinessAccount() {}

// Setters
void BusinessAccount::setNegativeBalance(double balance) {
    this->negativeBalance = balance;
}

double BusinessAccount::getNegativeBalance() const {
    return negativeBalance;
}

// Overridden functions
void BusinessAccount::display() 
{
    Account::display();
    cout << "Negative Balance: " << negativeBalance << endl;
    cout << "Total Transactions for the month: " << totalTransactions << endl;
}

void BusinessAccount::withdraw(const double amount) 
{
    double balanceAmount = atof(getBalance());
    balanceAmount -= amount;
    
    if (balanceAmount < 0) {
        negativeBalance -= balanceAmount;
        balanceAmount = 0;
    }

    // Update balance
    snprintf(balance, sizeof(balance), "%.2f", balanceAmount);
    
    totalTransactions += amount;

    // Record the transaction
   Transaction transaction = transaction.setTransactionData();
    transactions.push_back(transaction);

    if (totalTransactions > 20000000) {
        double fee = amount * 0.03;
        snprintf(balance, sizeof(balance), "%.2f", atof(getBalance()) - fee);
    }
}

void BusinessAccount::deposit(const double amount) {
    double balanceAmount = atof(getBalance());
    balanceAmount += amount;

    // Update balance
    snprintf(balance, sizeof(balance), "%.2f", balanceAmount);

    totalTransactions += amount;

    // Record the transaction
    Transaction transaction = transaction.setTransactionData();
    transactions.push_back(transaction);

    if (totalTransactions > 20000000) {
        double fee = amount * 0.03;
        snprintf(balance, sizeof(balance), "%.2f", atof(getBalance()) - fee);
    }
}

void BusinessAccount::transfer(const double amount, Account &toAccount) {
    withdraw(amount);  
    toAccount.deposit(amount);  
    totalTransactions += amount;

    // Record the transaction
    Transaction transaction = transaction.setTransactionData();
    transactions.push_back(transaction);

    if (totalTransactions > 20000000) {
        double fee = amount * 0.03;
        snprintf(balance, sizeof(balance), "%.2f", atof(getBalance()) - fee);
    }
}


void BusinessAccount::clearNegativeBalance() {
    negativeBalance = 0;
}

void BusinessAccount::incrementNegativeBalance() {
    if (negativeBalance > 0) {
        negativeBalance *= 1.1;  // Increase by 10%
    }
}

void BusinessAccount::showNegativeBalance() const {
    cout << "Current Negative Balance: " << negativeBalance << endl;
}
