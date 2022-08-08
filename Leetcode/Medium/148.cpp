#include "../../headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// Merge Sort
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
             
    }
};





// Cheat Approach
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        ListNode *list = new ListNode(0), *h = head, *ans = head;
        vector<int> v;
        int i = 0, j = 0;
        while(head)
        {
            v.push_back(head->val);
            head = head -> next;
            i++;
        }
        sort(begin(v), end(v));
        while(i--)
        {
            list->val = v[j];
            list = list -> next;
            j++;
        }
        return ans;
    }
};