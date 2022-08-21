#include "../../headers.h"

class Solution
{
public:
    int s[26], maxcnt = 0, r = 0;
    int leastInterval(vector<char> &tasks, int n)
    {
        for (char c : tasks)
            s[c - 'A']++;
        
        // count the max occurence of element
        for (int i = 0; i < 26; i++)
            maxcnt = max(maxcnt, s[i]);
        
        // count the element which has maxcnt == max occuring element
        for (int i = 0; i < 26; i++)
            r += s[i] == maxcnt;
        
        // rest is intuition based ;)
        return max(int(tasks.size()), (maxcnt - 1) * (n + 1) + r);
    }
};