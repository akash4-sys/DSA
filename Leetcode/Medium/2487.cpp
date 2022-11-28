#include "headers.h"

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
    ListNode *removeNodes(ListNode *head)
    {
        stack<int> st;
        while(head)
        {
            while(st.size() && st.top() < head->val)
                st.pop();
            st.push(head->val);
            head = head->next;
        }

        int i = st.size() - 1;
        vector<int> v(st.size());
        while(!st.empty())
            v[i--] = st.top(), st.pop();

        ListNode *ans = new ListNode(), *h = ans;
        for(int n: v)
        {
            h->next = new ListNode(n);
            h = h->next;
        }
        return ans->next;
    }
};


class Solution
{
    void deleteNode(ListNode* node) 
    {
        auto *next = node->next;
        *node = *next;
        delete next;
    }

public:
    ListNode *removeNodes(ListNode *head)
    {
        auto h = head;
        stack<int> st;
        while(head && head->next)
        {
            if(head->next->val > head->val)
                deleteNode(head);
            head = head->next;
        }
        return h;
    }
};