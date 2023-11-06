#include "../../headers.h"

class Solution
{
    string ans = "";
    void check(string &s, int l, int r)
    {
        for (; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++);
        if (ans.size() < r - l)
            ans = s.substr(l + 1, r - l - 1);
    }

public:
    string longestPalindrome(string &s)
    {
        for (int i = 0; i < s.size(); i++)
            check(s, i, i), check(s, i, i + 1);
        return ans;
    }
};

// Manacher's Algorithm
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int N = s.length();
        if (N == 0)
            return "";
        if (N == 1)
            return s;

        // Pos count considering string length to be even as well
        N = 2 * N + 1;
        vector<int> lps(N);
        lps[0] = 0;
        lps[1] = 1;
        int C = 1, R = 2, i = 0, mir, maxLpsLen = 0;
        int maxLpsCenterPos = 0, start = -1, end = -1, diff = -1;

        for (i = 2; i < N; i++)
        {
            mir = 2 * C - i;
            lps[i] = 0;
            diff = R - i;
            if (diff > 0)
                lps[i] = min(lps[mir], diff);

            while (((i + lps[i]) < N && (i - lps[i])) && ((i + lps[i] + 1) % 2 == 0 || (s[(i + lps[i] + 1) / 2] == s[(i - lps[i] - 1) / 2])))
            {
                lps[i]++;
            }

            if (lps[i] > maxLpsLen)
            {
                maxLpsLen = lps[i];
                maxLpsCenterPos = i;
            }

            if (i + lps[i] > R)
            {
                C = i;
                R = i + lps[i];
            }
        }
        start = (maxLpsCenterPos - maxLpsLen) / 2;
        end = start + maxLpsLen - 1;
        string ans = "";
        for (int i = start; i <= end; i++)
        {
            ans += s[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("babad");
}