#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(string acctNum, double bal) : accountNumber(acctNum), balance(bal) {}

void Account::display() const {
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
}

void Account::deposit(double amount) {
    if(amount > 0) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance: " << balance << endl;
    } else {
        cout << "Deposit amount must be positive!" << endl;
    }
}

void Account::withdraw(double amount) {
    if(amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrew " << amount << ". New balance: " << balance << endl;
    } else {
        cout << "Insufficient funds or invalid withdrawal amount!" << endl;
    }
}

Account::~Account() {}