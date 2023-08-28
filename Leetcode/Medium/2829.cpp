#include "../headers.h"

class Solution
{
public:
    int minimumSum(int n, int k)
    {
        unordered_map<int, int> ump;
        for (int num = 1; num < (k - num); num++) {
            ump[k - num] = 1;
        }
        
        int result = 0, count = 0;
        for (int num = 1; count < n; num++) {
            if (!ump.count(num)) {
                count++;
                result += num; 
            }
        }
        return result;
    }
};