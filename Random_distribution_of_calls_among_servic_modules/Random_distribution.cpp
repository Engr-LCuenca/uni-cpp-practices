#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_CALLS = 400;
const int MODULES = 4;

// Print a number with two decimal places
void printTwoDecimals(double value) {
    int integerPart = static_cast<int>(value);
    int decimalPart = static_cast<int>((value - integerPart) * 100 + 0.5);
    if (decimalPart >= 100) {
        integerPart += 1;
        decimalPart = 0;
    }

    cout << integerPart << ".";
    if (decimalPart < 10) {
        cout << "0";
    }
    cout << decimalPart;
}

// Validate and return the number of calls entered by the user
int getValidCallCount() {
    int n;
    do {
        cout << "Number of calls N = ";
        cin >> n;
        if (n < 100 || n > MAX_CALLS || n % MODULES != 0) {
            cout << "Error: N must be a multiple of 4 and between [100, 400]." << endl;
        }
    } while (n < 100 || n > MAX_CALLS || n % MODULES != 0);

    return n;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int n = getValidCallCount();
    int calls[MAX_CALLS] = {0};
    int frequency[MODULES] = {0};

    // Generate random calls and count how many go to each module
    for (int i = 0; i < n; ++i) {
        calls[i] = rand() % MODULES + 1;
        ++frequency[calls[i] - 1];
    }

    // Calculate expected values and acceptable range
    double expectedFrequency = static_cast<double>(n) / MODULES;
    double minAcceptable = expectedFrequency * 0.8;
    double maxAcceptable = expectedFrequency * 1.2;

    // Find the most and least used modules
    int maxCalls = frequency[0];
    int minCalls = frequency[0];
    for (int i = 1; i < MODULES; ++i) {
        if (frequency[i] > maxCalls) {
            maxCalls = frequency[i];
        }
        if (frequency[i] < minCalls) {
            minCalls = frequency[i];
        }
    }

    // Print the report
    cout << "\nREFERENCE OUTPUT" << endl;
    cout << "Expected frequency: ";
    printTwoDecimals(expectedFrequency);
    cout << " calls" << endl;

    cout << "Acceptable range: [";
    printTwoDecimals(minAcceptable);
    cout << ", ";
    printTwoDecimals(maxAcceptable);
    cout << "]" << endl;

    bool balanced = true;
    for (int i = 0; i < MODULES; ++i) {
        double percentage = (static_cast<double>(frequency[i]) / n) * 100.0;
        cout << "Module " << (i + 1) << ": " << frequency[i] << " calls - ";
        printTwoDecimals(percentage);
        cout << "%" << endl;

        if (frequency[i] < minAcceptable || frequency[i] > maxAcceptable) {
            balanced = false;
        }
    }

    cout << "Most used module: ";
    bool first = true;
    for (int i = 0; i < MODULES; ++i) {
        if (frequency[i] == maxCalls) {
            if (!first) {
                cout << ", ";
            }
            cout << (i + 1);
            first = false;
        }
    }
    cout << " (" << maxCalls << " calls)" << endl;

    cout << "Least used module: ";
    first = true;
    for (int i = 0; i < MODULES; ++i) {
        if (frequency[i] == minCalls) {
            if (!first) {
                cout << ", ";
            }
            cout << (i + 1);
            first = false;
        }
    }
    cout << " (" << minCalls << " calls)" << endl;

    cout << "Difference: " << (maxCalls - minCalls) << " calls" << endl;
    cout << "Is the distribution balanced? " << (balanced ? "YES" : "NO") << endl;

    return 0;
}
