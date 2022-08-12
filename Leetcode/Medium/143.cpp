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
    void reorderList(ListNode *head)
    {
        vector<ListNode*> v;
        ListNode *h = head;
        while (head)
        {
            v.push_back(head);
            head = head->next;
        }

        int l = 1, r = v.size()-1;
        for(int i = 0; i < v.size(); i++, h = h->next)
        {
            if(i%2 == 0)
                h->next = v[r--];
            else
                h->next = v[l++];
        }
        h->next =NULL;
    }
};