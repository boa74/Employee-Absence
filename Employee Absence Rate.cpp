
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ofstream global("EMPLOYEE_ABSENCE.txt"); // Open the file for writing

int NumOfEmployees();
int TotDaysAbsent(int NumbersOfEmployees);
double AverageAbsent(int totDaysAbsent, int numOfEmployees);

int main() {
    cout << "Calculate the average number of days a company's employees are absent" << endl;

    int a = NumOfEmployees();
    int b = TotDaysAbsent(a); // Getting b variable as a totalDays/absent
    double c = AverageAbsent(b, a);
    string name = "BOA KIM";

    global << "The " << a << " employees were absent a total of " << b << " days." << endl;
    global << "The average number of days absent is " << fixed << setprecision(2) << c << " days." << endl;
    global << "Programmer: " << name << endl;
    global.close(); // Close the file after writing

    return 0;
}

// Function to get the number of employees
int NumOfEmployees() {
    int n;
    cout << "The number of employees in the company: ";
    cin >> n;

    while (n < 1) {
        cout << "Invalid data. Please put the number greater than 1." << endl;
        cin >> n;
    }
    return n;
}

// Function to calculate the total days absent
int TotDaysAbsent(int NumbersOfEmployees) {
    int idNumber = 0;
    int missedDays, totDaysAbsent = 0;

    for (int a = 0; a < NumbersOfEmployees; a++) {
        cout << "ID number of the Employee (4 digits or less): ";
        cin >> idNumber;
        cout << "The number of days that the employee missed during the past year: ";
        cin >> missedDays;

        while (missedDays <= 0) {
            cout << "The negative number is invalid. Please input a number above 0" << endl;
            cin >> missedDays;
        }

        totDaysAbsent += missedDays;

        // Write to the file
        global << setw(10) << left << "Employee ID" << setw(15) << left << "Days Absent" << endl;
        global << setw(10) << left << idNumber << setw(15) << left << missedDays << endl;
    }

    return totDaysAbsent;
}

// Function to calculate the average days absent
double AverageAbsent(int totDaysAbsent, int numOfEmployees) {
    return static_cast<double>(totDaysAbsent) / static_cast<double>(numOfEmployees);
}
