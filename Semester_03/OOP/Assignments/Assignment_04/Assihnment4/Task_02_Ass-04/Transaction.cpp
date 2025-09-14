#include "Transaction.h"
#include <iostream>
using namespace std;

// Constructor
Transaction::Transaction(int tId, int sId, const string &sName, int rId, const string &rName, double amount, Date date)
{
  transactionId = tId;
    senderId = sId;
    senderName = sName;
    receiverId = rId;
    receiverName = rName;
    this->amount = amount;
    this->date = date;
}

 Transaction Transaction::setTransactionData()
{
    cout << "Enter Transaction ID: ";
    cin >> transactionId;
    cout << "Enter Sender ID: ";
    cin >> senderId;
    cout << "Enter Sender Name: ";
    cin >> senderName;
    cout << "Enter Receiver ID: ";
    cin >> receiverId;
    cout << "Enter Receiver Name: ";
    cin >> receiverName;
    cout << "Enter Amount: ";
    cin >> amount;
    cout << "Enter Date: ";
    cin >> date;
    return *this;
}

// Getters
int Transaction::getTransactionId() const
{
    return transactionId;
}

int Transaction::getSenderId() const
{
    return senderId;
}

std::string Transaction::getSenderName() const
{
    return senderName;
}

int Transaction::getReceiverId() const
{
    return receiverId;
}

std::string Transaction::getReceiverName() const
{
    return receiverName;
}

double Transaction::getAmount() const
{
    return amount;
}

Date Transaction::getDate() const
{
    return date;
}

// Setters
void Transaction::setTransactionId(int tId)
{
    transactionId = tId;
}

void Transaction::setSenderId(int sId)
{
    senderId = sId;
}

void Transaction::setSenderName(const std::string &sName)
{
    senderName = sName;
}

void Transaction::setReceiverId(int rId)
{
    receiverId = rId;
}

void Transaction::setReceiverName(const std::string &rName)
{
    receiverName = rName;
}

void Transaction::setAmount(double amount)
{
    this->amount = amount;
}

void Transaction::setDate(Date date)
{
    this->date = date;
}

// Display
void Transaction::displayTransaction() const
{
    cout << "Transaction ID: " << transactionId;
    cout << "\nSender ID: " << senderId;
    cout << "\nSender Name: " << senderName;
    cout << "\nReceiver ID: " << receiverId;
    cout << "\nReceiver Name: " << receiverName;
    cout << "\nAmount Transferred: $" << amount;
    cout << "\nDate of Transaction: ";
    date.display(); 
    cout << endl;
}
