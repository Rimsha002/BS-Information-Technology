#include "Account.h"
#include <iostream>
#include <cstring> 

// Constructors
Account::Account() {
    accountNumber = "";
    accountHolder = Person();
    // Initialize balance to '0'
    for (int i = 0; i < sizeof(balance); ++i) {
        balance[i] = '0';
    }
    balance[sizeof(balance) - 1] = '\0'; 
}

Account::Account(string accNum, Person holder, const char* initBalance) {
    accountNumber = accNum;
    accountHolder = holder;
    // Copy initBalance to balance
    int i;
    for (i = 0; i < sizeof(balance) - 1 && initBalance[i] != '\0'; ++i) {
        balance[i] = initBalance[i];
    }
    balance[i] = '\0'; 
}

Account::Account(const Account &acc) {
    accountNumber = acc.accountNumber;
    accountHolder = acc.accountHolder;
    // Copy balance from acc to this balance
    int i;
    for (i = 0; i < sizeof(balance) - 1 && acc.balance[i] != '\0'; ++i) {
        balance[i] = acc.balance[i];
    }
    balance[i] = '\0'; 
}

// Destructor
Account::~Account() {
    // Clean up if needed
}

// Setters
void Account::setAccountNumber(const string &accNum) {
    accountNumber = accNum;
}

void Account::setAccountHolder(const Person &holder) {
    accountHolder = holder;
}

void Account::setBalance(const char* newBalance) {
    // Copy newBalance to balance
    int i;
    for (i = 0; i < sizeof(balance) - 1 && newBalance[i] != '\0'; ++i) {
        balance[i] = newBalance[i];
    }
    balance[i] = '\0'; 
}

// Getters
string Account::getAccountNumber() const {
    return accountNumber;
}

Person Account::getAccountHolder() const {
    return accountHolder;
}

const char* Account::getBalance() const {
    return balance;
}

// Methods
void Account::checkBalance() const {
    cout << "Current balance: ";
    for (int i = 0; i < sizeof(balance) && balance[i] != '\0'; ++i) {
        cout << balance[i];
    }
    cout << endl;
}

void Account::viewTransactionHistory() const {
    cout << "Transaction History: " << endl;
    for (const auto& transaction : transactions) {
        transaction.displayTransaction();  
    }
}

