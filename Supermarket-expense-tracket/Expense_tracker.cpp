#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Expense {
    string name;
    string category;
    double amount;
};

void printMenu() {
    cout << "\n=== Supermarket Expense Tracker ===\n";
    cout << "1. Add expense\n";
    cout << "2. View all expenses\n";
    cout << "3. View summary\n";
    cout << "4. View category summary\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

string readLine(const string& prompt) {
    cout << prompt;
    string value;
    getline(cin, value);
    return value;
}

double readPositiveAmount(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cout << "Invalid amount. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void addExpense(vector<Expense>& expenses) {
    Expense expense;
    expense.name = readLine("Enter item name: ");
    expense.category = readLine("Enter category: ");
    expense.amount = readPositiveAmount("Enter amount: ");

    expenses.push_back(expense);
    cout << "Expense added successfully.\n";
}

void viewAllExpenses(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << "\n=== Recorded Expenses ===\n";
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << i + 1 << ". " << expenses[i].name
             << " | Category: " << expenses[i].category
             << " | Amount: $" << fixed << setprecision(2) << expenses[i].amount << "\n";
    }
}

double getTotal(const vector<Expense>& expenses) {
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.amount;
    }
    return total;
}

void viewSummary(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    double total = getTotal(expenses);
    double average = total / expenses.size();

    const Expense* highest = &expenses[0];
    for (const auto& expense : expenses) {
        if (expense.amount > highest->amount) {
            highest = &expense;
        }
    }

    cout << "\n=== Summary ===\n";
    cout << "Total expenses: $" << fixed << setprecision(2) << total << "\n";
    cout << "Average expense: $" << fixed << setprecision(2) << average << "\n";
    cout << "Highest expense: " << highest->name << " ($" << fixed << setprecision(2) << highest->amount << ")\n";
    cout << "Number of entries: " << expenses.size() << "\n";
}

void viewCategorySummary(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    vector<string> categories;
    vector<double> totals;

    for (const auto& expense : expenses) {
        bool found = false;
        for (size_t i = 0; i < categories.size(); ++i) {
            if (categories[i] == expense.category) {
                totals[i] += expense.amount;
                found = true;
                break;
            }
        }
        if (!found) {
            categories.push_back(expense.category);
            totals.push_back(expense.amount);
        }
    }

    cout << "\n=== Category Summary ===\n";
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << categories[i] << ": $" << fixed << setprecision(2) << totals[i] << "\n";
    }
}

int main() {
    vector<Expense> expenses;
    int choice = 0;

    while (true) {
        printMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number from the menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                viewAllExpenses(expenses);
                break;
            case 3:
                viewSummary(expenses);
                break;
            case 4:
                viewCategorySummary(expenses);
                break;
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}
