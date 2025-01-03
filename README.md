# Banking System in C++

This is a simple Banking System implemented in C++ that demonstrates the use of Object-Oriented Programming (OOP) concepts like inheritance, encapsulation, polymorphism, and abstraction. The system allows for creating and managing two types of bank accounts: Savings and Checking accounts, each with specific functionalities.

## Features:
- Create Savings and Checking Accounts.
- Deposit funds into any account.
- Withdraw funds, considering the overdraft limit for Checking accounts.
- Apply interest on Savings accounts.
- Maintain logs of system activities with a logger for transparency.

## Project Structure

### Files Overview:
1. **Account.h / Account.cpp**: Contains the base class `Account`, which represents the basic account features such as balance and account number. Provides methods for deposit, withdrawal, and displaying account details.
2. **CheckingAccount.h / CheckingAccount.cpp**: A subclass of `Account`, which adds overdraft protection and overrides the withdrawal method to allow overdrafts up to a certain limit.
3. **SavingsAccount.h / SavingsAccount.cpp**: Another subclass of `Account`, which adds an interest rate and provides the functionality to apply interest to the account balance.
4. **Logger.h / Logger.cpp**: Contains the `Logger` class, used for logging events (such as account creation, deposit, and withdrawal actions) into a text file for auditing or tracking purposes.
5. **main.cpp**: The main file that simulates the Banking System with a simple menu interface where users can create accounts, perform transactions, and view logs of actions.

## How the Banking System Works

### Creating Accounts:
- **Savings Account**: Created by entering the account number, initial balance, and interest rate. Interest is applied to the balance periodically.
- **Checking Account**: Created with an account number, initial balance, and overdraft limit. Users can withdraw up to the overdraft limit in addition to their balance.

### Operations:
- **Deposit**: Users can deposit money into any account. The system logs the transaction.
- **Withdraw**: Users can withdraw money from the account. If the withdrawal exceeds the balance in a Checking account, the system will allow an overdraft up to the defined overdraft limit.
- **Apply Interest**: The Savings account has an interest rate, and interest is added to the balance after each deposit.

### Logging:
- A **Logger** is implemented to track events such as creating accounts, making deposits and withdrawals, and ending the system operation.
- All logs are saved to a file named `banking_log.txt`.

## How to Use

1. **Compile the Code:**
    - Use any C++ compiler to compile the code. For example:
      ```bash
      g++ main.cpp Account.cpp SavingsAccount.cpp CheckingAccount.cpp Logger.cpp -o BankingSystem
      ```
2. **Run the Program:**
    - After compilation, run the resulting executable (`BankingSystem`):
      ```bash
      ./BankingSystem
      ```

3. **Menu Options:**
    - **1:** Create a Savings Account.
    - **2:** Create a Checking Account.
    - **3:** Find an Account and Display Details.
    - **4:** Exit the Program.

4. **Logs:**
    - Logs of all operations (like deposits, withdrawals, account creation, etc.) are saved in the `banking_log.txt` file.


## Future Improvements
- Add features for transferring money between accounts.
- Introduce user authentication to secure account access.
- Add a feature to handle multiple users.
- Improve error handling and user input validation.

