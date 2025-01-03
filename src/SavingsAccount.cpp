#include "SavingsAccount.h"
#include <iostream>
#include "Logger.h"
using namespace std;

SavingsAccount::SavingsAccount(string acctNum, double bal, double rate)
    : Account(acctNum, bal), interestRate(rate) {}

void SavingsAccount::applyInterest(Logger& logger) {
    double interest = balance * interestRate / 100;
    balance += interest;
    cout << "Applied interest of " << interest << " to account " << accountNumber << ". New balance: " << balance << endl;

    // Log this event
    string logMessage = "Applied interest of " + to_string(interest) + " to account " + accountNumber + ". New balance: " + to_string(balance);
    logger.log(logMessage);  // Log the interest application event
}

void SavingsAccount::display() const {
    Account::display();
    cout << "Interest Rate: " << interestRate << "%" << endl;
}
