#include "../../headers.h"

class Solution 
{
public:
    bool checkIfPangram(string s) 
    {
        int ch[26] = {0};
        for(char c: s)
            ch[c - 'a']++;
        for(int i = 0; i < 26; i++)
            if(!ch[i])
                return false;
        return true;
    }
};

class Solution 
{
public:
    bool checkIfPangram(string s) 
    {
        int x = 0;
        for(auto c: s)
            x |= (1 << (c - 'a'));
        return x == 67108863;   //last 26 bits are 1 in this number
    }
};