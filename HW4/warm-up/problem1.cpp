#include <iostream>
using namespace std;

class InchSize
{
public:
    InchSize(int wholeInches = 0, int sixteenths = 0);
    void Print() const;
    InchSize operator+(InchSize rhs);

private:
    int inches;
    int sixteenths;
};

InchSize InchSize::operator+(InchSize rhs)
{
    InchSize totalSize;

    totalSize.inches = inches + rhs.inches;
    totalSize.sixteenths = sixteenths + rhs.sixteenths;

    // If sixteenths is greater than or equal to an inch,
    // carry 1 to inches.
    if (totalSize.sixteenths >= 16)
    {
        totalSize.inches += 1;
        totalSize.sixteenths -= 16;
    }

    return totalSize;
}

InchSize::InchSize(int wholeInches, int sixteenthsOfInch)
{
    inches = wholeInches;
    sixteenths = sixteenthsOfInch;
}

void InchSize::Print() const
{
    cout << inches << " " << sixteenths << "/16 inches" << endl;
}

int main()
{
    InchSize size1(5, 15);
    InchSize size2(9, 11);
    InchSize sumSize;

    sumSize = size1 + size2;

    sumSize.Print();

    return 0;
}

/*
Expected output:

15 10/16 inches
*/
