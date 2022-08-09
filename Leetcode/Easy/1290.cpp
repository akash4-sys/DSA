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
    int getDecimalValue(ListNode *head)
    {
        string bin = "";
        while (head)
        {
            bin += to_string(head->val);
            head = head->next;
        }

        int base = 1, ans = 0;
        for (int i = bin.length() - 1; i >= 0; i--)
        {
            if(bin[i] == '1')
                ans += base;
            base *= 2;
        }

        return ans;
    }
};