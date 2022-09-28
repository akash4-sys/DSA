#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Time complexity - O(NlogK)
// Space Complexity - O(N)

class Solution 
{
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *merged = new ListNode(INT_MIN), *head = merged;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
                head->next = l1, l1 = l1->next;
            else
                head->next = l2, l2 = l2->next;
            head = head->next;
        }
        head->next = l1 ? l1 : l2;
        return merged->next;
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int low, int high)
    {
        if(low > high) return NULL;
        if(low == high) return lists[low];
        if(low + 1 == high)
            return mergeTwoLists(lists[low], lists[high]);
        
        int mid = low + ((high - low) / 2);
        ListNode *left = mergeLists(lists, low, mid);
        ListNode *right = mergeLists(lists, mid + 1, high);
        return mergeTwoLists(left, right);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) return NULL;
        return mergeLists(lists, 0, lists.size() - 1);
    }
};





// Time complexity - O(N^2)
// Space complexity - O(N)

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty()) return NULL;

        ListNode *ans = new ListNode(INT_MIN);
        for (ListNode *li : lists)
        {
            ListNode *temp = new ListNode(INT_MIN), *head = temp;
            while (ans && li)
            {
                if(ans->val < li->val) head->next = ans, ans = ans->next;
                else head->next = li, li = li->next;
                head = head->next;
            }
            head->next = ans ? ans : li;
            ans = temp -> next;
        }
        return ans->next;
    }
};



// Merge two lists at a time
class Solution
{
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(INT_MIN), *head = ans;
        while (l1 && l2)
        {
            if(l1->val < l2->val) head->next = l1, l1 = l1->next;
            else head->next = l2, l2 = l2->next;
            head = head->next;
        }
        head->next = l1 ? l1 : l2;
        return ans->next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty()) return NULL;

        ListNode *ans = new ListNode(INT_MIN);
        for (ListNode *li : lists)
            ans = mergeTwoLists(ans, li);
        return ans->next;
    }
};




// cheat way
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        ListNode *head = new ListNode(), *temp = head;
        vector<int> v;
        for (ListNode *i : lists)
            for (ListNode *curr = i; curr != NULL; curr = curr->next)
                v.push_back(curr->val);

        sort(v.begin(), v.end());
        for (int n : v)
            temp->next = new ListNode(n), temp = temp->next;
        return head->next;
    }
};