#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    vector<string> transactionLog; // Add transaction log

    void logTransaction(const string& entry); // Log transactions

public:
    Account(string acctNum, double bal);
    virtual void display() const;
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    void displayTransactions() const; // Display transaction log
    virtual ~Account();

    string getAccountNumber() const {
        // New getter method
        return accountNumber;
    }
};

#endif // ACCOUNT_H
