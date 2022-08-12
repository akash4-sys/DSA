#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        if (!head->next->next)
            return {-1, -1};
        int i = 1, first = INT_MAX, last = 0, minD = INT_MAX;
        while (head && head->next->next)
        {
            int c = head->next->val, l = head->val, r = head->next->next->val;
            if ((c > l && c > r) || (c < l && c < r))
            {
                first = min(first, i);
                if(last != 0)
                    minD = min(minD, i - last);
                last = i;
            }
            i++;
            head = head->next;
        }
        if (minD == INT_MAX)
            return {-1, -1};
        return {minD, last - first};
    }
};