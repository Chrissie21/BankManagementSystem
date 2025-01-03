#include "CheckingAccount.h"
#include <iostream>
#include "Logger.h"  // Include the logger for logging
using namespace std;

CheckingAccount::CheckingAccount(string acctNum, double bal, double limit)
    : Account(acctNum, bal), overdraftLimit(limit) {}

void CheckingAccount::withdraw(double amount, Logger& logger) {
    string logMessage;

    if(amount > 0 && amount <= balance + overdraftLimit) {
        balance -= amount;
        cout << "Withdrew " << amount << ". New balance: " << balance << endl;

        // Log the withdrawal
        logMessage = "Withdrew " + to_string(amount) + " from Checking Account " + accountNumber + ". New balance: " + to_string(balance);
        logger.log(logMessage);  // Log the withdrawal action
    } else {
        cout << "Insufficient funds or invalid withdrawal amount!" << endl;

        // Log the failed withdrawal attempt
        logMessage = "Failed withdrawal attempt of " + to_string(amount) + " from Checking Account " + accountNumber + ". Insufficient funds or invalid amount.";
        logger.log(logMessage);  // Log the failure
    }
}

void CheckingAccount::display() const {
    Account::display();
    cout << "Overdraft Limit: " << overdraftLimit << endl;
}
