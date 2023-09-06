#include "headers.h"

class Solution
{
public:
    int minimumOperations(string s)
    {
        int five = 0, zero = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if ((zero && (s[i] == '0' || s[i] == '5')) || (five && (s[i] == '7' || s[i] == '2')))
                return s.size() - i - 2;
            zero |= s[i] == '0';
            five |= s[i] == '5';
        }
        return s.size() - zero;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(1)

class Solution
{
public:
    int minimumOperations(string s)
    {
        int n = s.size();
        if (n <= 2 && stoi(s) < 25) {
            if (stoi(s) % 25 == 0)
                return 0;
            return n - count(s.begin(), s.end(), '0');
        }

        int ans = n;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (((s[i] - '0') * 10 + (s[j] - '0')) % 25 == 0)
                    ans = min(ans, n - i - 2);
        return ans == n ? n - count(s.begin(), s.end(), '0') : ans;
    }
};