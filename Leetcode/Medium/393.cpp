#include "../../headers.h"

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int count = 0;
        for(int d: data)
        {
            if(!count)
            {
                if((d >> 5) == 0b110)
                    count = 1;
                else if((d >> 4) == 0b1110)
                    count = 2;
                else if((d >> 3) == 0b11110)
                    count = 3;
                else if(d >> 7)
                    return false;
            }
            else 
            {
                if((d >> 6) != 0b10)
                    return false;
                count--;
            }
        }
        return count == 0;
    }
};