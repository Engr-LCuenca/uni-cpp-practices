#include <iostream>
using namespace std;

// Function prototypes
int getIncidentCount();
int getShift(int incidentNumber);
int getSeverity(int incidentNumber);

int main() {
    int totalIncidents = getIncidentCount();

    int globalCriticalCount = 0;
    int globalSeveritySum = 0;
    int morningCount = 0;
    int morningSeveritySum = 0;
    int morningCriticalCount = 0;
    int afternoonCount = 0;
    int afternoonSeveritySum = 0;
    int afternoonCriticalCount = 0;

    for (int i = 1; i <= totalIncidents; ++i) {
        cout << "\n--- Incident Data Entry - Incident #" << i << " ---\n";

        int shift = getShift(i);
        int severity = getSeverity(i);

        globalSeveritySum += severity;
        if (severity == 5) {
            ++globalCriticalCount;
        }

        if (shift == 1) {
            ++morningCount;
            morningSeveritySum += severity;
            if (severity == 5) {
                ++morningCriticalCount;
            }
        } else {
            ++afternoonCount;
            afternoonSeveritySum += severity;
            if (severity == 5) {
                ++afternoonCriticalCount;
            }
        }
    }

    cout << "\n=============================================\n";
    cout << "            INCIDENT REPORT                 \n";
    cout << "=============================================\n";

    double criticalPercentage = (totalIncidents > 0) ? (globalCriticalCount * 100.0) / totalIncidents : 0.0;
    cout << "Total and critical incidents: " << totalIncidents << " incidents; "
         << globalCriticalCount << " critical (" << criticalPercentage << "%)\n";

    double overallAverage = (totalIncidents > 0) ? static_cast<double>(globalSeveritySum) / totalIncidents : 0.0;
    cout << "Overall average severity: " << overallAverage << "\n";

    cout << "Average severity by shift: ";
    double morningAverage = (morningCount > 0) ? static_cast<double>(morningSeveritySum) / morningCount : 0.0;
    double afternoonAverage = (afternoonCount > 0) ? static_cast<double>(afternoonSeveritySum) / afternoonCount : 0.0;

    if (morningCount > 0) {
        cout << "Morning: " << morningAverage;
    } else {
        cout << "Morning: No incidents";
    }

    if (afternoonCount > 0) {
        cout << " | Afternoon: " << afternoonAverage << "\n";
    } else {
        cout << " | Afternoon: No incidents\n";
    }

    cout << "Critical incidents by shift: Morning: " << morningCriticalCount
         << " | Afternoon: " << afternoonCriticalCount << "\n";

    cout << "Shift with the highest average severity: ";
    if (morningCount == 0 && afternoonCount == 0) {
        cout << "No data available\n";
    } else if (morningAverage > afternoonAverage) {
        cout << "Morning\n";
    } else if (afternoonAverage > morningAverage) {
        cout << "Afternoon\n";
    } else {
        cout << "Tie\n";
    }

    cout << "=============================================\n";
    return 0;
}

int getIncidentCount() {
    int n;
    while (true) {
        cout << "Enter the number of incidents (5 to 50): ";
        cin >> n;
        if (n >= 5 && n <= 50) {
            return n;
        }
        cout << "[Error] Invalid number. Please try again.\n";
    }
}

int getShift(int incidentNumber) {
    int shift;
    while (true) {
        cout << "Incident #" << incidentNumber << " - Shift (1 = Morning, 2 = Afternoon): ";
        cin >> shift;
        if (shift == 1 || shift == 2) {
            return shift;
        }
        cout << "[Error] Invalid shift. Enter 1 or 2.\n";
    }
}

int getSeverity(int incidentNumber) {
    int severity;
    while (true) {
        cout << "Incident #" << incidentNumber << " - Severity level (1 to 5): ";
        cin >> severity;
        if (severity >= 1 && severity <= 5) {
            return severity;
        }
        cout << "[Error] Invalid severity. Enter a value from 1 to 5.\n";
    }
}
