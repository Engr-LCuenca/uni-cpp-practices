#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class BankAccount {
private:
    string ownerName;
    double balance;

public:
    BankAccount(string name, double initialBalance) : ownerName(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
            return;
        }

        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return;
        }

        balance -= amount;
        cout << "Withdrawal successful.\n";
    }

    void showBalance() const {
        cout << "Current balance: $" << fixed << setprecision(2) << balance << "\n";
    }

    string getOwnerName() const {
        return ownerName;
    }
};

double readAmount(const string& prompt) {
    double amount;
    while (true) {
        cout << prompt;
        cin >> amount;
        if (cin.fail() || amount <= 0) {
            cout << "Please enter a valid positive amount.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return amount;
        }
    }
}

void printMenu() {
    cout << "\n=== Basic Bank Account Simulator ===\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. View balance\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    string ownerName;
    double initialBalance;

    cout << "Enter account owner name: ";
    getline(cin, ownerName);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    if (initialBalance < 0) {
        cout << "Initial balance cannot be negative.\n";
        return 1;
    }

    BankAccount account(ownerName, initialBalance);

    while (true) {
        printMenu();
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid option. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                double amount = readAmount("Enter deposit amount: ");
                account.deposit(amount);
                break;
            }
            case 2: {
                double amount = readAmount("Enter withdrawal amount: ");
                account.withdraw(amount);
                break;
            }
            case 3:
                account.showBalance();
                break;
            case 4:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}
