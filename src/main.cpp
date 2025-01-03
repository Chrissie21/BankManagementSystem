#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main() {
    SavingsAccount savings("S123", 1000.0, 5.0);
    CheckingAccount checking("C123", 500.0, 200.0);

    cout << "Savings Account Details:" << endl;
    savings.display();
    savings.deposit(200);
    savings.withdraw(100);
    savings.applyInterest();
    savings.display();

    cout << "\nChecking Account Details:" << endl;
    checking.display();
    checking.deposit(300);
    checking.withdraw(700);
    checking.display();

    return 0;
}