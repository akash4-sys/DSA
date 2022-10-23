#include "headers.h"

class Solution
{
    bool calc(vector<string> &t1, vector<string> &t2)
    {
        if (t1[1][0] > t2[0][0])
            return true;
        if (t1[1][0] == t2[0][0])
        {
            if (t1[1][1] > t2[0][1])
                return true;
            if (t1[1][1] == t2[0][1])
                if (t1[1][3] > t2[0][3])
                    return true;
                else if (t1[1][3] == t2[0][3])
                    if (t1[1][4] >= t2[0][4])
                        return true;
        }
        return false;
    }

public:
    bool haveConflict(vector<string> &t1, vector<string> &t2)
    {
        return (calc(t1, t2) && calc(t2, t1));
    }
};