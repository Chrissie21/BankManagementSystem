#include "SavingsAccount.h"
#include <iostream>
#include "Logger.h"

using namespace std;

SavingsAccount::SavingsAccount(string acctNum, double bal, double rate)
    : Account(acctNum, bal), interestRate(rate) {}

void SavingsAccount::deposit(double amount, Logger& logger) {
    if(amount > 0) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
        // Log the deposit action
        logger.log("Deposited " + to_string(amount) + " to Savings Account " + accountNumber + ". New balance: " + to_string(balance));
    } else {
        cout << "Deposit amount must be positive!" << endl;
    }
}

void SavingsAccount::applyInterest() {
    double interest = balance * interestRate / 100;
    balance += interest;
    cout << "Applied interest of " << interest << " to account " << accountNumber << ". New balance: " << balance << endl;
    // Log the interest application
    Logger logger("banking_log.txt"); // or use existing logger
    logger.log("Applied interest of " + to_string(interest) + " to Savings Account " + accountNumber + ". New balance: " + to_string(balance));
}

void SavingsAccount::display() const {
    Account::display();
    cout << "Interest Rate: " << interestRate << "%" << endl;
}
