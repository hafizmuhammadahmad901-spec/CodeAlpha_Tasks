
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int n;

    cout << "===== CGPA CALCULATOR =====" << endl;

    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of courses!";
        return 0;
    }

    string courseNames[50];
    double grades[50];
    int creditHours[50];

    double totalCredits = 0;
    double totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name: ";
        cin >> courseNames[i];

        cout << "Enter grade points: ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        if (grades[i] < 0 || creditHours[i] <= 0)
        {
            cout << "Invalid input!";
            return 0;
        }

        totalCredits = totalCredits + creditHours[i];

        totalGradePoints = totalGradePoints +
                           (grades[i] * creditHours[i]);
    }

    // Calculate semester GPA
    double GPA = totalGradePoints / totalCredits;

    // Input previous academic record
    double previousCGPA, previousCredits;

    cout << "\nEnter previous CGPA (0 if first semester): ";
    cin >> previousCGPA;

    cout << "Enter previous credit hours: ";
    cin >> previousCredits;

    if (previousCGPA < 0 || previousCredits < 0 ||
        (previousCredits == 0 && previousCGPA != 0))
    {
        cout << "Invalid previous record!";
        return 0;
    }

    // Calculate overall CGPA
    double CGPA;

    if (previousCredits == 0)
    {
        CGPA = GPA;
    }
    else
    {
        CGPA = ((previousCGPA * previousCredits) +
                totalGradePoints) /
               (previousCredits + totalCredits);
    }

    // Display individual course details
    cout << "\n===== COURSE DETAILS =====\n";

    cout << left << setw(20) << "Course"
         << setw(12) << "Grade"
         << "Credit Hours" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(20) << courseNames[i]
             << setw(12) << grades[i]
             << creditHours[i] << endl;
    }

    // Display final result
    cout << fixed << setprecision(2);

    cout << "\n===== FINAL RESULT =====\n";

    cout << "Total Credit Hours: " << totalCredits << endl;

    cout << "Total Grade Points: " << totalGradePoints << endl;

    cout << "Semester GPA: " << GPA << endl;

    cout << "Overall CGPA: " << CGPA << endl;

    cout << "\nThank you for using CGPA Calculator!";

    return 0;
}
