#include "../../headers.h"
#include "../../LinkedList.h"

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k, NULL);
        int len = 0;
        for (auto h = head; h; h = h->next, len++);

        for (int sz = len / k, r = len % k, i = 0, n = sz; k; k--)
        {
            ans[i++] = head;
            n += r-- > 0;
            for (; n > 1; head = head->next, n--);
            if (head)
            {
                auto h = head->next;
                head->next = NULL;
                head = h;
            }
            n = sz;
        }
        return ans;
    }
};

// @lc app=leetcode id=725 lang=cpp