#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include "Logger.h"  // Include the Logger header

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string acctNum, double bal, double rate);
    void deposit(double amount, Logger& logger) override;  // Add Logger parameter here
    void applyInterest();
    void display() const override;
};

#endif // SAVINGSACCOUNT_H
