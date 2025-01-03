#include <iostream>
#include "Account.h"

int main() {
    Account acc("Chris Balele", 1000.0);
    acc.display();

    acc.deposit(500.0);
    acc.display();

    acc.withdraw(300.0);
    acc.display();

    acc.withdraw(2000.0); // Should show insufficient balance.

    return 0;
}
