#include "headers.h"

class Solution
{
public:
    vector<double> convertTemperature(double c)
    {
        return {c + 273.15, (c * 1.80) + 32.00};
    }
};