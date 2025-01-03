#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;

public:
    Account(string acctNum, double bal);
    virtual void display() const;
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual ~Account();
};

#endif // ACCOUNT_H