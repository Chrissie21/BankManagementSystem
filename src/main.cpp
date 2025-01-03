#include "Account.h"
#include "SavingsAccount.h"

int main() {
    // Create an Account object
    Account acc1("A123", 1000.0);
    acc1.display();
    acc1.deposit(500.0);
    acc1.withdraw(200.0);
    acc1.display();

    // Create a SavingsAccount object
    SavingsAccount savingsAcc1("S123", 1500.0, 5.0);  // 5% interest rate
    savingsAcc1.display();
    savingsAcc1.applyInterest();
    savingsAcc1.deposit(300.0);
    savingsAcc1.withdraw(100.0);
    savingsAcc1.display();

    return 0;
}
