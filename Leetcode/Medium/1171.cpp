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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        vector<int> v;
        ListNode *ans = new ListNode(0), *h = head, *c = ans;
        vector<int>::iterator it;
        int sum = 0;
        while (head)
        {
            sum += head->val;
            it = find(begin(v), end(v), sum);
            if (it != end(v))
            {
                int j = (it - v.begin()) + 1;
                while (j < v.size())
                    v[j] = INT_MIN, j++;
                v.push_back(INT_MIN);
            }
            else
                v.push_back(sum);
            
            if(sum == 0)
                v = vector<int>(v.size(), INT_MIN);
            head = head->next;
        }

        for (int x: v)
        {
            if (x != INT_MIN)
            {
                c->next = new ListNode(h->val);
                c = c->next;
            }
            h = h->next;
        }
        return ans->next;
    }
};