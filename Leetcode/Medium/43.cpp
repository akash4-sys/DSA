#include "../../headers.h"

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string s1 = (num1.length() > num2.length()) ? num1 : num2;
        string s2 = (num1.length() <= num2.length()) ? num1 : num2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        int pos = 1, res = 0;
        for (char m : s2)
        {
            int x = m - '0', r = 0;
            stack<int> num;
            num.push(0);
            for (int i=0; i < s1.length(); i++)
            {
                int y = s1[i] - '0';
                num.push(num.top() * 10 + (((x * y) + r) % 10));
                r = (x * y) / 10;
                if(i == s1.size()-1)
                    num.push(r);
            }


            int n = 0;
            while (!num.empty())
            {
                n = (n * 10) + num.top() % 10;
                num.pop();
            }
            
            n *= pos;
            pos *= 10;
            res += n;
        }

        string ans = to_string(res);
        reverse(ans.begin(), ans.end());
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

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string s1 = (num1.length() > num2.length()) ? num1 : num2;
        string s2 = (num1.length() <= num2.length()) ? num1 : num2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        int pos = 1, res = 0;
        for (char m : s2)
        {
            int x = m - '0', num = 0, r = 0;
            for (char c : s1)
            {
                int y = c - '0';
                num = num * 10 + (((x * y) + r) % 10);
                r = (x * y) / 10;
                if(s1[s1.size()-1] == c){ 
                    num = (num * 10) + r;
                }
            }

            int n = 0;
            while (num > 0)
            {
                n = (n * 10) + num % 10;
                num /= 10;
            }

            n *= pos;
            pos *= 10;
            res += n;
        }

        string ans = to_string(res);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
