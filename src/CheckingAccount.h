#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string acctNum, double bal, double limit);
    void deposit(double amount, Logger& logger) override;  // Add Logger parameter here
    void withdraw(double amount, Logger& logger) override; // Add Logger parameter here
    void display() const override;
};

#endif // CHECKINGACCOUNT_H
