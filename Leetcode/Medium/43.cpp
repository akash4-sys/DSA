#include "../../headers.h"

class Solution {
public:
    string multiply(string a, string b) {
        int m = a.length(), n = b.length();
        string ans(m+n, '0');
        for(int j = n-1; j >= 0; j--)
        {
            int c = 0;
            for(int i = m - 1, k = n-j-1; i >= 0 || c; k++)
            {
                if(i >= 0)
                    c += (a[i--] - '0') * (b[j] - '0');
                c += ans[k] - '0';
                ans[k] = c % 10 + '0';
                c /= 10;
            }
        }

        while(ans.size() > 1 && ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Wrong approach for larger int sizes
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string s1 = (num1.length() > num2.length()) ? num1 : num2;
        string s2 = (num1.length() <= num2.length()) ? num1 : num2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        long long int res = 0, pos = 1;
        for (char m : s2)
        {
            long long int x = m - '0', r = 0;
            stack<long long int> num;
            num.push(0);
            for (int i=0; i < s1.length(); i++)
            {
                long long int y = s1[i] - '0';
                num.push(((x * y) + r) % 10);
                r = ((x * y)+r) / 10;
                if(i == s1.size()-1)
                    num.push(r);
            }

            long long int n = 0;
            while (!num.empty())
            {
                n = (n * 10) + num.top() % 10;
                num.pop();
            }

            n /= 10;
            n *= pos;
            pos *= 10;
            res += n;
        }

        string ans = to_string(res);
        return ans;
    }
};

// Absoultely easiest way
class Solution
{
public:
    int stringToInt(string s)
    {
        int num = 0;
        for (char c : s)
            num = (num * 10) + (c - '0');
        return num;
    }

    string multiply(string num1, string num2)
    {
        int x = stringToInt(num1);
        int y = stringToInt(num2);
        int sans = x * y;
        return to_string(sans);
    }
};