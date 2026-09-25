#include "GradeHistogram.h"

// Constructor
GradeHistogram::GradeHistogram()
{
    resetHistogram();
}

// Reset all histogram counts to zero
void GradeHistogram::resetHistogram()
{
    for (int i = 0; i < 6; i++)
    {
        histogram[i] = 0;
    }
}

// Problem 1:
// Count each grade immediately when it is entered
void GradeHistogram::countGradesAsEntered()
{
    int numberOfStudents;
    int grade;

    resetHistogram();

    cout << "Grade Histogram - Count Grades As Entered" << endl;

    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "Enter grade for student "
             << i + 1
             << " (0-5): ";

        cin >> grade;

        if (grade >= 0 && grade <= 5)
        {
            histogram[grade]++;
        }
        else
        {
            cout << "Invalid grade. Please enter a grade from 0 to 5."
                 << endl;

            i--;
        }
    }

    printHistogram();
}

// Problem 2:
// Store grades first, then count them
void GradeHistogram::storeGradesThenCount()
{
    int grade;

    grades.clear();
    resetHistogram();

    cout << "\nGrade Histogram - Store Grades Then Count" << endl;

    cout << "Enter grades from 0 to 5." << endl;
    cout << "Enter -1 when finished." << endl;

    while (true)
    {
        cout << "Enter grade: ";
        cin >> grade;

        if (grade == -1)
        {
            break;
        }

        if (grade >= 0 && grade <= 5)
        {
            grades.push_back(grade);
        }
        else
        {
            cout << "Invalid grade. Please enter a grade from 0 to 5."
                 << endl;
        }
    }

    calculateHistogram();

    printHistogram();
}

// Scan the vector and count each grade
void GradeHistogram::calculateHistogram()
{
    for (int i = 0; i < grades.size(); i++)
    {
        histogram[grades[i]]++;
    }
}

// Print histogram
void GradeHistogram::printHistogram()
{
    cout << "\nHistogram:" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << histogram[i]
             << " grade(s) of "
             << i
             << endl;
    }
}
