#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

// Utility functions
void createSavingsAccount(vector<shared_ptr<Account>>& accounts) {
    string acctNum;
    double balance, rate;
    cout << "Enter Account Number: ";
    cin >> acctNum;
    cout << "Enter Initial Balance: ";
    cin >> balance;
    cout << "Enter Interest Rate (%): ";
    cin >> rate;

    accounts.push_back(make_shared<SavingsAccount>(acctNum, balance, rate));
    cout << "Savings Account created successfully!\n";
}

void createCheckingAccount(vector<shared_ptr<Account>>& accounts) {
    string acctNum;
    double balance, limit;
    cout << "Enter Account Number: ";
    cin >> acctNum;
    cout << "Enter Initial Balance: ";
    cin >> balance;
    cout << "Enter Overdraft Limit: ";
    cin >> limit;

    accounts.push_back(make_shared<CheckingAccount>(acctNum, balance, limit));
    cout << "Checking Account created successfully!\n";
}

shared_ptr<Account> findAccount(const vector<shared_ptr<Account>>& accounts, const string& acctNum) {
    for (const auto& account : accounts) {
        if (account->getAccountNumber() == acctNum) { // Assuming `getAccountNumber()` exists in the Account class
            return account;
        }
    }
    cout << "Account not found.\n";
    return nullptr; // Return null if account isn't found
}

void runMenu(vector<shared_ptr<Account>>& accounts) {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Find Account and Display Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createSavingsAccount(accounts);
            break;
            case 2:
                createCheckingAccount(accounts);
            break;
            case 3: {
                string acctNum;
                cout << "Enter Account Number: ";
                cin >> acctNum;
                auto account = findAccount(accounts, acctNum);
                if (account) {
                    account->display();
                } else {
                    cout << "Account not found.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting the program.\n";
            break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}


int main() {
    vector<shared_ptr<Account>> accounts;

    runMenu(accounts);

    return 0;
}
