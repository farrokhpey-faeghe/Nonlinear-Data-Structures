#include <iostream>
#include <string>

using namespace std;

class Applicant
{
public:
    // Default constructor
    Applicant();

    // Updates the applicant information
    void SetInformation(string newName,
                        int newExperience,
                        char newFullTime);

    // Prints the applicant information
    void Print() const;

private:
    string name;
    int experience;
    char fullTime;
};


// Default constructor using a constructor initializer list
Applicant::Applicant()
    : name("Unfilled"),
      experience(-1),
      fullTime('-')
{
}


// Update all applicant information
void Applicant::SetInformation(string newName,
                               int newExperience,
                               char newFullTime)
{
    name = newName;
    experience = newExperience;
    fullTime = newFullTime;
}


// Print the current applicant information
void Applicant::Print() const
{
    cout << "Applicant: " << name
         << ", Experience: " << experience
         << ", Full Time: " << fullTime
         << endl;
}


int main()
{
    string newName;
    int newExperience;
    char newFullTime;

    // Creating this object automatically calls
    // the default Applicant constructor.
    Applicant myApplicant;

    // Print the default values.
    myApplicant.Print();

    // Read new applicant information.
    cin >> newName;
    cin >> newExperience;
    cin >> newFullTime;

    // Replace the default information.
    myApplicant.SetInformation(
        newName,
        newExperience,
        newFullTime
    );

    // Print the updated information.
    myApplicant.Print();

    return 0;
}
