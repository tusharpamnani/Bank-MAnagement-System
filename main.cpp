#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Customer {
    int customerId;
    string name;
    string address;
    string contactInfo;
};

struct BankAccount {
    int accountNumber;
    int customerId;
    string accountType;
    double balance;
};

vector<Customer> customers;
vector<BankAccount> accounts;

void addCustomer() {
    Customer newCustomer;
    cout << "Enter customer ID: ";
    cin >> newCustomer.customerId;
    cin.ignore();

    cout << "Enter name: ";
    getline(cin, newCustomer.name);

    cout << "Enter address: ";
    getline(cin, newCustomer.address);

    cout << "Enter contact information: ";
    getline(cin, newCustomer.contactInfo);

    customers.push_back(newCustomer);
    cout << "CUSTOMER ADDED SUCCESSFULLY!" << endl;
}

void createAccount() {
    BankAccount newAccount;
    cout << "Enter customer ID for the account: ";
    cin >> newAccount.customerId;
    cin.ignore(); // Ignore the newline character left in the input stream

    cout << "Enter account type (e.g., savings, checking): ";
    getline(cin, newAccount.accountType);

    static int accountCounter = 1;
    newAccount.accountNumber = accountCounter++;
    
    newAccount.balance = 0.0; 

    accounts.push_back(newAccount);
    cout << "ACCOUNT CREATED SUCCESSFULLY!" << endl;
}

void deposit() {
    int accountNumber;
    double amount;
    cout << "Enter account number for deposit: ";
    cin >> accountNumber;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            account.balance += amount;
            cout << "DEPOSIT SUCCESSFUL!" << endl;
            return;
        }
    }

    cout << "Account with number " << accountNumber << " not found." << endl;
}

void withdraw() {
    int accountNumber;
    double amount;
    cout << "Enter account number for withdrawal: ";
    cin >> accountNumber;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            if (account.balance >= amount) {
                account.balance -= amount;
                cout << "WITHDRAWAL SUCCESSFUL!" << endl;
            } else {
                cout << "Insufficient balance for withdrawal." << endl;
            }
            return;
        }
    }

    cout << "Account with number " << accountNumber << " not found." << endl;
}

void displayAccounts() {
    cout << "--- Bank Accounts ---" << endl;
    for (const auto& account : accounts) {
        cout << "Account Number: " << account.accountNumber << endl;
        cout << "Customer ID: " << account.customerId << endl;
        cout << "Account Type: " << account.accountType << endl;
        cout << "Balance: $" << account.balance << endl;
        cout << "---------------------" << endl;
    }
}

// Function to display the main menu
void displayMenu() {
    cout << "----- Bank Management System -----" << endl;
    cout << "1. Add Customer" << endl;
    cout << "2. Create Account" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Display Accounts" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                createAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                displayAccounts();
                break;
            case 0:
                cout << "Thank you for choosing us! Have a nice day!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
