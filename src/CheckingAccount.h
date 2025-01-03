#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string acctNum, double bal, double limit);
    void withdraw(double amount) override;
    void display() const override;
};

#endif // CHECKINGACCOUNT_H