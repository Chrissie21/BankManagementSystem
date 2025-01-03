#include "SavingsAccount.h"

// Constructor for SavingsAccount
SavingsAccount::SavingsAccount(string acctNum, double bal, double rate) 
    : Account(acctNum, bal), interestRate(rate) {}

// Apply interest
void SavingsAccount::applyInterest() {
    double interest = balance * interestRate / 100;
    balance += interest;
    cout << "Applied interest of " << interest << " to account " << accountNumber << ". New balance: " << balance << endl;
}

// Overridden display method for SavingsAccount
void SavingsAccount::display() {
    Account::display();  // Call Account's display method
    cout << "Interest Rate: " << interestRate << "%" << endl;
}
