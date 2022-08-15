#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time complexity - O(n)
// Space complexity - O(n)
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        int ans = INT_MIN;
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = v.size() - 1; i < j; i++, j--)
            ans = max(v[i] + v[j], ans);

        return ans;
    }
};

// Time complexity - O(n)
// Space complexity - O(1)

class Solution
{
public:
    ListNode *reverseList(ListNode *curr, ListNode *prev = nullptr)
    {
        while (curr != nullptr)
        {
            swap(curr->next, prev);
            swap((prev != nullptr) ? prev->next : prev, curr);
        }
        return prev;
    }

    int pairSum(ListNode *head)
    {
        int ans = INT_MIN;
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = reverseList(slow);
        while (slow)
        {
            ans = max(ans, slow->val + head->val);
            slow = slow->next;
            head = head->next;
        }
        return ans;
    }
};