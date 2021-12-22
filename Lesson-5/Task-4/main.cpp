#include <iostream>
#include <cmath>

using namespace std;

struct EquationCoefficient
{
    int a;
    int b;
    int c;
};

struct EquationRoots
{
    float x1;
    float x2;
};

int InputCoefficients ()
{
    int coef = 0;
    cin >> coef;
    return coef;
}

EquationRoots EquationSolution(float a, float b, float c)
{
    EquationRoots root = {0, 0};
    float discriminant = b*b - 4*a*c;

    if (discriminant < 0)
    {
        root.x1 = 0;
        root.x2 = 0;
    }
    else if (discriminant == 0)
    {
        root.x1 = -b/(2*a);
        root.x2 = -b/(2*a);
    }
    else
    {
        root.x1 = (-b + sqrt(discriminant))/2*a;
        root.x2 = (-b - sqrt(discriminant))/2*a;
    }
    return root;
}

EquationRoots EquationSolution(float a, float b)
{
    EquationRoots root;
    root.x1 = 0;
    root.x2 = -(b/a);
    return root;
}

int main()
{
    EquationCoefficient coefficient;
    EquationRoots roots;

    cout << "Enter coefficients of quadratic equation (abc or ab)" << endl;

    coefficient.a = InputCoefficients();
    coefficient.b = InputCoefficients();
    coefficient.c = InputCoefficients();

    if (coefficient.c == 0)
        roots = EquationSolution(coefficient.a, coefficient.b);
    else
        roots = EquationSolution(coefficient.a, coefficient.b, coefficient.c);

    cout << "x1 = " << roots.x1 << endl
         << "x2 = " << roots.x2 << endl;

    return 0;
}
