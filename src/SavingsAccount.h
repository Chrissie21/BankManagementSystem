#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string acctNum, double bal, double rate);
    void applyInterest();
    void display() const override;
};

#endif // SAVINGSACCOUNT_H