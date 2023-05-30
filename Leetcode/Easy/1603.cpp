#include "../../headers.h"

class ParkingSystem
{
    int car[4] = {0};
public:
    ParkingSystem(int big, int medium, int small)
    {
        car[1] = big;
        car[2] = medium;
        car[3] = small;
    }
    
    bool addCar(int carType)
    {
        if (--car[carType] < 0)
            return 0;
        return 1;
    }
};