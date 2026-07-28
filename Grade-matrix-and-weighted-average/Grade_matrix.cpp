#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Configuration constants
const int STUDENTS = 30;
const int SUBJECTS = 3;
const double PASSING_THRESHOLD = 11.0;
const double PC_WEIGHT = 0.2;
const double EP_WEIGHT = 0.3;
const double EF_WEIGHT = 0.5;

// Calculate the weighted average of a student
double calculateAverage(const int grades[SUBJECTS]) {
    return grades[0] * PC_WEIGHT + grades[1] * EP_WEIGHT + grades[2] * EF_WEIGHT;
}

// Print a number with two decimal places
void printValue(double value) {
    int integerPart = static_cast<int>(value);
    int decimalPart = static_cast<int>((value - integerPart) * 100 + 0.5);
    cout << integerPart << "." << (decimalPart < 10 ? "0" : "") << decimalPart;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int grades[STUDENTS][SUBJECTS];
    int passed = 0, failed = 0, maxStudent = 1, minStudent = 1;
    double sum = 0.0, maxAverage = -1.0, minAverage = 21.0;

    cout << "OUTPUT\nStudent\tPC\tEP\tEF\tAverage\tCondition\n";

    for (int student = 0; student < STUDENTS; ++student) {
        for (int subject = 0; subject < SUBJECTS; ++subject) {
            grades[student][subject] = rand() % 21; // Random grade from 0 to 20
        }

        double average = calculateAverage(grades[student]);
        sum += average;

        bool isPassed = average >= PASSING_THRESHOLD;
        (isPassed ? passed : failed)++;

        if (average > maxAverage) {
            maxAverage = average;
            maxStudent = student + 1;
        }
        if (average < minAverage) {
            minAverage = average;
            minStudent = student + 1;
        }

        cout << student + 1 << "\t" << grades[student][0] << "\t" << grades[student][1]
             << "\t" << grades[student][2] << "\t";
        printValue(average);
        cout << "\t" << (isPassed ? "PASSED" : "FAILED") << "\n";
    }

    double overallAverage = sum / STUDENTS;

    cout << "\nFull Execution Summary:\n";
    cout << "Overall average: ";
    printValue(overallAverage);
    cout << "\nHighest average: student " << maxStudent << " (";
    printValue(maxAverage);
    cout << ")\nLowest average: student " << minStudent << " (";
    printValue(minAverage);
    cout << ")\nPassed: " << passed << " | Failed: " << failed << "\n";

    return 0;
}

