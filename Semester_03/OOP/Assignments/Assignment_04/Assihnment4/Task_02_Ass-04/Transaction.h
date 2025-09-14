#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Date.h"

class Transaction {
private:
    int transactionId;
    int senderId;
    string senderName;
    int receiverId;
    string receiverName;
    double amount;
    Date date;

public:
    // Constructor
    Transaction(int transactionId, int senderId, const std::string& senderName, int receiverId, const string& receiverName, double amount, Date date);

    Transaction setTransactionData();

    // Getters
    int getTransactionId() const;
    int getSenderId() const;
    string getSenderName() const;
    int getReceiverId() const;
    string getReceiverName() const;
    double getAmount() const;
    Date getDate() const;

    // Setters
    void setTransactionId(int transactionId);
    void setSenderId(int senderId);
    void setSenderName(const string& senderName);
    void setReceiverId(int receiverId);
    void setReceiverName(const string& receiverName);
    void setAmount(double amount);
    void setDate(Date date);

    // Method to display transaction details
    void displayTransaction() const;
};


#endif