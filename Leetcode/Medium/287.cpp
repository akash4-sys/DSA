#include "../../headers.h"

class Solution
{
public:
    int findDuplicate(vector<int> &v)
    {
        int slow = v[0], fast = v[0];
        while (1)
        {
            slow = v[slow];
            fast = v[v[fast]];
            if (slow == fast)
                break;
        }
        
        for (slow = v[0]; slow != fast;)
            slow = v[slow], fast = v[fast];
        return fast;
    }
};