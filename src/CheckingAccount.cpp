#include "CheckingAccount.h"
#include <iostream>
#include "Logger.h"

using namespace std;

CheckingAccount::CheckingAccount(string acctNum, double bal, double limit)
    : Account(acctNum, bal), overdraftLimit(limit) {}

void CheckingAccount::deposit(double amount, Logger& logger) {
    if(amount > 0) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
        // Log the deposit action
        logger.log("Deposited " + to_string(amount) + " to Checking Account " + accountNumber + ". New balance: " + to_string(balance));
    } else {
        cout << "Deposit amount must be positive!" << endl;
    }
}

void CheckingAccount::withdraw(double amount, Logger& logger) {
    if(amount > 0 && amount <= balance + overdraftLimit) {
        balance -= amount;
        cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        // Log the withdrawal action
        logger.log("Withdrew " + to_string(amount) + " from Checking Account " + accountNumber + ". New balance: " + to_string(balance));
    } else {
        cout << "Insufficient funds or invalid withdrawal amount!" << endl;
    }
}

void CheckingAccount::display() const {
    Account::display();
    cout << "Overdraft Limit: " << overdraftLimit << endl;
}
