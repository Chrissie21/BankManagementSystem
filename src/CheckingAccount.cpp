#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount(string acctNum, double bal, double limit)
    : Account(acctNum, bal), overdraftLimit(limit) {}

void CheckingAccount::withdraw(double amount) {
    if(amount > 0 && amount <= balance + overdraftLimit) {
        balance -= amount;
        cout << "Withdrew " << amount << ". New balance: " << balance << endl;
    } else {
        cout << "Insufficient funds or invalid withdrawal amount!" << endl;
    }
}

void CheckingAccount::display() const {
    Account::display();
    cout << "Overdraft Limit: " << overdraftLimit << endl;
}