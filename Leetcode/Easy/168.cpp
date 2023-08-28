#include "../../headers.h"

class Solution
{
public:
    string convertToTitle(int n)
    {
        string s = "";
        while (n)
        {
            n--;
            s = (char)((n % 26) + "A") + s;
            n = n / 26;
        }
        return s;
    }
};



class Solution
{
public:
    string convertToTitle(int n)
    {
        string s = "A";
        for (int i = 1; i < n; i++)
            if (i % 26 == 0)
            {
                int j = s.size() - 1;
                for (; j >= 0 && s[j] == 'Z'; j--)
                    s[j] = 'A';
                if (j >= 0)
                    s[j]++;
                else
                    s += "A";
            }
            else
                s.back()++;
        return s;
    }
};