#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    // Constructor
    Account(string acctNum, double bal);

    // Methods
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
    virtual void display();  // Virtual function for future overrides
};

#endif  // ACCOUNT_H
