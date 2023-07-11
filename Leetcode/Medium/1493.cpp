#include "../../headers.h"

class Solution
{
public:
    int longestSubarray(vector<int> &v)
    {
        int i = 0, j = 0, k = 1;
        for (; j < v.size(); j++)
        {
            k -= !v[j];
            k += (k < 0 && !v[i++]);
        }
        return j - i - 1;
    }
};



class Solution
{
public:
    int longestSubarray(vector<int> &v)
    {
        int zero = 0, ans = 0, j = 0;
        for (int i = 0; i < v.size(); i++)
        {
            zero += !v[i];
            for (; zero > 1; zero -= !v[j++]);
            ans = max(ans, i - j);
        }
        return ans;
    }
};



class Solution
{
public:
    int longestSubarray(vector<int> &v)
    {
        int ones = 0, zero = 0, ans = 0, tz = 0, j = 0;
        for (int n : v)
        {
            ones += n;
            zero += !n;
            if (zero > 1)
            {
                ans = max(ans, ones);
                while (zero > 1)
                    ones -= v[j], zero -= !v[j++];
            }
            tz += !n;
        }
        return max(ans, ones - (tz == 0));
    }
};