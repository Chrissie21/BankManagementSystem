#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Logger.h"

using namespace std;

// Utility functions
void createSavingsAccount(vector<shared_ptr<Account>>& accounts, Logger& logger) {
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
    // Log the action
    logger.log("Created Savings Account with number " + acctNum);
}

void createCheckingAccount(vector<shared_ptr<Account>>& accounts, Logger& logger) {
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
    // Log the action
    logger.log("Created Checking Account with number " + acctNum);
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

void runMenu(vector<shared_ptr<Account>>& accounts, Logger& logger) {
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
                createSavingsAccount(accounts, logger);
                break;
            case 2:
                createCheckingAccount(accounts, logger);
                break;
            case 3: {
                string acctNum;
                cout << "Enter Account Number: ";
                cin >> acctNum;
                auto account = findAccount(accounts, acctNum);
                if (account) {
                    account->display();
                    // Log display details action
                    logger.log("Displayed details for account number " + acctNum);
                } else {
                    cout << "Account not found.\n";
                    // Log failed attempt
                    logger.log("Failed to display details for account number " + acctNum + " (account not found)");
                }
                break;
            }
            case 4:
                cout << "Exiting the program.\n";
                // Log exit action
                logger.log("User exited the program.");
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}


int main() {
    vector<shared_ptr<Account>> accounts;
    Logger logger("banking_log.txt"); // Initialize logger

    // Log the program startup
    logger.log("Banking system started.");

    // Account creation
    createSavingsAccount(accounts, logger);
    createCheckingAccount(accounts, logger);

    // Perform a deposit transaction example and log it
    auto account = findAccount(accounts, "S123");
    if (account) {
        account->deposit(200); // Assuming the deposit method was implemented in the `Account` class.
        logger.log("Deposited 200 to Savings Account S123.");
    }

    // Display the menu and proceed with other actions
    runMenu(accounts, logger);

    // Log the program end
    logger.log("Banking system ended.");
    return 0;
}
