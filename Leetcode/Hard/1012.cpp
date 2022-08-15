#include "../../headers.h"

class Solution
{
public:
    int factorial(int n)
    {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    int numDupDigitsAtMostN(int n)
    {
        string s = to_string(n);
        int digits = s.length(), dig = digits, ans = 0, fact9 = 362880;

        while (dig--)
            ans += (9 * (fact9 / factorial(10 - dig)));

        vector<int> visited(10, 0);

        for (int i = 0; i < digits; i++)
        {
            int small = 0;
            for (int j = 0; j < s[i] - '0'; j++)
                if (!visited[j])
                    small++;
                
            if(i == 0)
                small--;

            int next = 1, rem = 10 - i - 1;
            for (int j = i + 1; j < digits; j++)
                next *= rem, rem--;

            ans += (small * next);

            if (!visited[s[i] - '0'])
                visited[s[i] - '0'] = 1;
            else
                break;
        }

        if (accumulate(begin(visited), end(visited), 0) == digits)
            ans++;
        
        ans = n - ans;
        return ans;
    }
};