#include "Account.h"

// Constructor
Account::Account(string acctNum, double bal) : accountNumber(acctNum), balance(bal) {}

// Deposit method
void Account::deposit(double amount) {
    if(amount > 0) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << accountNumber << ". New balance: " << balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

// Withdraw method
void Account::withdraw(double amount) {
    if(amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrew " << amount << " from account " << accountNumber << ". New balance: " << balance << endl;
    } else {
        cout << "Invalid withdrawal amount." << endl;
    }
}

// Get balance method
double Account::getBalance() {
    return balance;
}

// Display method
void Account::display() {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
}
