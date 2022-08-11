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
        vector<int> res, arr;
        unordered_map<int, int> umap;
        ListNode *ans = new ListNode();
        int sum = 0;
        while(head)
        {
            sum += head->val;
            if(umap.count(sum))
            {
                umap.find(umap.begin(), umap.end(), sum);
            }
            umap[sum]++;
            head = head->next;
        }
    }
};