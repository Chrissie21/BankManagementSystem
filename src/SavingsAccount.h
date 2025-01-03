#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // Constructor
    SavingsAccount(string acctNum, double bal, double rate);

    // Method to apply interest
    void applyInterest();

    // Overriding display method
    void display() override;
};

#endif  // SAVINGS_ACCOUNT_H
