#include "Account.h"
#include <iostream>
#include <sstream>
#include <iomanip> // For formatting

#include "Logger.h"
using namespace std;

// Constructor
Account::Account(string acctNum, double bal) : accountNumber(acctNum), balance(bal) {
    logTransaction("Account created with balance " + to_string(bal));
}

// Log transaction
void Account::logTransaction(const string& entry) {
    transactionLog.push_back(entry);
}

// Display account details
void Account::display() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << fixed << setprecision(2) << balance << endl;
}

// Deposit
void Account::deposit(double amount, Logger& logger) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
        logTransaction("Deposited " + to_string(amount));
    } else {
        cout << "Deposit amount must be positive!" << endl;
    }
}

// Withdraw
void Account::withdraw(double amount, Logger& logger) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        logTransaction("Withdrew " + to_string(amount));
    } else {
        cout << "Insufficient funds or invalid withdrawal amount!" << endl;
    }
}

// Display transaction history
void Account::displayTransactions() const {
    cout << "Transaction History for Account " << accountNumber << ":" << endl;
    for (const string& entry : transactionLog) {
        cout << "- " << entry << endl;
    }
}

// Destructor
Account::~Account() {
    logTransaction("Account closed.");
}
