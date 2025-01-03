#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string accountHolderName;
    double balance;

public:
    Account(const std::string &name, double initialBalance);
    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
};

#endif
