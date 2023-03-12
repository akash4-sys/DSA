#include "../../headers.h"
#include "../../LinkedList.h"

// @ N^2 or NlogN can be used interchangebly

// Time complexity - O(NlogK)
// Space Complexity - O(1)

class Solution
{
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        ListNode *ans = new ListNode(INT_MIN), *head = ans;
        for (; a && b; head = head->next)
            if(a->val < b->val)
                head->next = a, a = a->next;
            else 
                head->next = b, b = b->next;
        head->next = a ? a : b;
        return ans->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& v)
    {
        if (v.empty())
            return NULL;
        for (int last = v.size() - 1; last;)
            for (int l = 0, r = last; l < r;)
            {
                v[l] = mergeTwoLists(v[l], v[r]);
                l++, r--;
                if (l >= r)
                    last = r;
            }
        return v[0];
    }
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


// Time complexity - O(NlogN)
// Space complexity - O(1)
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

// Merge Two lists recursively
class Solution
{
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (!a || !b)
            return a ? a : b;
        ListNode *res = NULL;
        if (a->val <= b->val)
            res = a, res->next = mergeTwoLists(a->next, b);
        else
            res = b, res->next = mergeTwoLists(a, b->next);
        return res;
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
// Time Complexity - O(NlogN) - Where N is total number of nodes in merged LinkedList
// Space Complexity - O(N)
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