#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(string acctNum, double bal, double rate)
    : Account(acctNum, bal), interestRate(rate) {}

void SavingsAccount::applyInterest() {
    double interest = balance * interestRate / 100;
    balance += interest;
    cout << "Applied interest of " << interest << " to account " << accountNumber << ". New balance: " << balance << endl;
}

void SavingsAccount::display() const {
    Account::display();
    cout << "Interest Rate: " << interestRate << "%" << endl;
}