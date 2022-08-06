#include "../../headers.h"

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        // convert int from double
        int rounds = ceil(1.0 * minutesToTest / minutesToDie);

        // log of buckets base rounds+1
        return ceil(log(buckets) / log(rounds + 1));
    }
};