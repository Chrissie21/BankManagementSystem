#include "Account.h"
#include <iostream>

Account::Account(const std::string &name, double initialBalance)
    : accountHolderName(name), balance(initialBalance) {}

void Account::deposit(double amount) {
    balance += amount;
    std::cout << "Deposited: " << amount << std::endl;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient balance!" << std::endl;
        return false;
    }
    balance -= amount;
    std::cout << "Withdrawn: " << amount << std::endl;
    return true;
}

void Account::display() const {
    std::cout << "Account Holder: " << accountHolderName
              << "\nBalance: " << balance << std::endl;
}
