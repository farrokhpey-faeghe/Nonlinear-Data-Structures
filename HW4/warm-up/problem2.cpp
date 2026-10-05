#include <iostream>
using namespace std;

class Volume
{
public:
    Volume(double numLiters = 0.0, double numMilliliters = 0.0);
    void Print() const;
    Volume operator+(Volume rhs);

private:
    double liters;
    double milliliters;
};

Volume::Volume(double numLiters, double numMilliliters)
{
    liters = numLiters;
    milliliters = numMilliliters;
}

// Overload + for two Volume objects
Volume Volume::operator+(Volume rhs)
{
    Volume totalVolume;

    totalVolume.liters = liters + rhs.liters;
    totalVolume.milliliters = milliliters + rhs.milliliters;

    return totalVolume;
}

void Volume::Print() const
{
    cout << liters << " liters, "
         << milliliters << " milliliters";
}

int main()
{
    double numLiters1;
    double numMilliliters1;
    double numLiters2;
    double numMilliliters2;

    cin >> numLiters1;
    cin >> numMilliliters1;
    cin >> numLiters2;
    cin >> numMilliliters2;

    Volume volume1(numLiters1, numMilliliters1);
    Volume volume2(numLiters2, numMilliliters2);

    Volume sum = volume1 + volume2;

    volume1.Print();
    cout << endl;

    volume2.Print();
    cout << endl;

    cout << "Sum: ";
    sum.Print();
    cout << endl;

    return 0;
}

/*
Example input:
11.0 276.0 2.0 194.5

Expected output:
11 liters, 276 milliliters
2 liters, 194.5 milliliters
Sum: 13 liters, 470.5 milliliters
*/
