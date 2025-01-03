#include <iostream>
#include <string>
using namespace std;

// Base class for Account
class Account {
protected:
    string accountNumber;
    double balance;

public:
    // Constructor
    Account(string acctNum, double bal) : accountNumber(acctNum), balance(bal) {}

    // Virtual method to display account details
    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Virtual method for depositing money
    virtual void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Virtual method for withdrawing money
    virtual void withdraw(double amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount!" << endl;
        }
    }

    virtual ~Account() {} // Virtual destructor
};

// Derived class for SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    // Constructor for SavingsAccount
    SavingsAccount(string acctNum, double bal, double rate)
        : Account(acctNum, bal), interestRate(rate) {}

    // Method to apply interest
    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Applied interest of " << interest << " to account " << accountNumber << ". New balance: " << balance << endl;
    }

    // Overridden display method for SavingsAccount
    void display() override {
        Account::display(); // Call Account's display method
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Main function
int main() {
    // Create a Savings Account
    SavingsAccount mySavings("123456", 1000.0, 5.0); // Account number, balance, interest rate

    // Display the initial state of the account
    cout << "Initial Account Details:" << endl;
    mySavings.display();

    // Apply interest
    mySavings.applyInterest();

    // Display the updated state of the account
    cout << "\nUpdated Account Details after applying interest:" << endl;
    mySavings.display();

    // Deposit some money
    cout << "\nMaking a deposit of 500.0:" << endl;
    mySavings.deposit(500.0);

    // Withdraw some money
    cout << "\nMaking a withdrawal of 200.0:" << endl;
    mySavings.withdraw(200.0);

    // Final display after deposit and withdrawal
    cout << "\nFinal Account Details:" << endl;
    mySavings.display();

    return 0;
}
