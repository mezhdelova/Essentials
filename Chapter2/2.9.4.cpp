#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
    double vector[] = { 1., 2., 3., 4., 5. };
    int n = sizeof(vector) / sizeof(vector[0]);
    double ArithmeticMean;
    double HarmonicMean;
    double GeometricMean;
    double RootMeanSquare;

    double sum = 0;
    for( int i = 0; i < n; i++)
    {
        sum += vector[i];
    }
    ArithmeticMean = sum / n;

    sum = 0;
    for( int i = 0; i < n; i++)
    {
        sum += 1 / vector[i];
    }
    HarmonicMean = n / sum;

    sum = 1;
    for( int i = 0; i < n; i++)
    {
        sum *= vector[i];
    }
    GeometricMean = pow(sum, (1. / n));

    sum = 0;
    for( int i = 0; i < n; i++)
    {
        sum += pow(vector[i], 2);
    }
    RootMeanSquare = sqrt(sum / n);

    cout << "Arithmetic Mean = " << ArithmeticMean << endl;
    cout << "Harmonic Mean = " << HarmonicMean << endl;
    cout << "Geometric Mean = " << GeometricMean << endl;
    cout << "RootMean Square = " << RootMeanSquare << endl;
    cout << endl;
    return 0;
}
