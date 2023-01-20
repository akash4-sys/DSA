#include "../../headers.h"

// Not easy if time complexity is less than O(N^3)

class Solution 
{
public:
    int sumOddLengthSubarrays(vector<int>& v)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int left = i, right = v.size() - i - 1;
            ans += v[i] * (left / 2 + 1) * (right / 2 + 1);
            ans += v[i] * ((left + 1) / 2) * ((right + 1) / 2);
        }
        return ans;
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(1)
class Solution 
{
public:
    int sumOddLengthSubarrays(vector<int>& v)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i, sum = 0; j < v.size(); j++)
                sum += v[j], ans += (j - i + 1) % 2 ? sum : 0;
        return ans;
    }
};