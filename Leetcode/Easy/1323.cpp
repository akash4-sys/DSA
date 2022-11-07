#include "../../headers.h"

class Solution 
{
public:
    int maximum69Number (int n) 
    {
        string s = to_string(n);
        for(char &c: s)
            if(c == '6')
            {
                c = '9';
                break;
            }
        return stoi(s);
    }
};