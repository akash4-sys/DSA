#include "headers.h"

class DataStream
{
    int v, k, c = 0;
public:
    DataStream(int v, int x)
    {
        this->v = v;
        k = x;
    }

    bool consec(int n)
    {
        if (n == v)
                c++;
        else c = 0;
        return c >= k;
    }
};
