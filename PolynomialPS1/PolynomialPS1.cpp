// COS30008, Problem Set 1, 2020

#include "Polynomial.h"

#include <cmath>

using namespace std;

double Polynomial::operator()(double aX) const
{
    double Result = 0.0;                                                

    for (int i = 0; i <= fDegree; i++)                                
    {
        Result += fCoeffs[i] * pow(aX, i);                             
    }

    return Result;                                                      
}

Polynomial Polynomial::getDifferential() const
{
    Polynomial Result;                                                  

    if (fDegree)  // not a constant                                   
    {
        Result.fDegree = fDegree - 1;                                   

        for (int i = 0; i <= Result.fDegree; i++)                     
        {
            Result.fCoeffs[i] = fCoeffs[i + 1] * (i + 1);                     
        }
    }

    return Result;                                                      
}

Polynomial Polynomial::getIndefiniteIntegral() const
{
    Polynomial Result;                                                  

    Result.fDegree = fDegree + 1;                                       

    for (int i = fDegree; i >= 0; i--)                                
    {
        Result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);                         
    }

    return Result;                                                      
}


double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
    Polynomial lTemp = getIndefiniteIntegral();                         

    return lTemp(aXHigh) - lTemp(aXLow);                            
}
