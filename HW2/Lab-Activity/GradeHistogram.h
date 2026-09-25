#ifndef GRADEHISTOGRAM_H
#define GRADEHISTOGRAM_H

#include <iostream>
#include <vector>

using namespace std;

class GradeHistogram
{
private:
    vector<int> grades;
    int histogram[6];

public:
    // Constructor
    GradeHistogram();

    // Reset all histogram counts to zero
    void resetHistogram();

    // Problem 1:
    // Count each grade immediately when it is entered
    void countGradesAsEntered();

    // Problem 2:
    // Store grades first, then count them
    void storeGradesThenCount();

    // Scan the vector and count each grade
    void calculateHistogram();

    // Print histogram
    void printHistogram();
};

#endif
