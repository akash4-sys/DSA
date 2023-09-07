#include "../../headers.h"

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
    Node(int _val): val(_val) {}
};


// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    Node *flatten(Node *head)
    {
        for (auto h = head; h; h = h->next)
            if (h->child)
            {
                auto next = h->next;
                h->next = h->child;
                h->next->prev = h;
                h->child = NULL;
                auto curr = h->next;
                for (; curr->next; curr = curr->next);
                curr->next = next;
                if (next)
                    next->prev = curr;
            }
        return head;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *curr = new Node(0), *h = curr;
        for (; head; head = head->next)
        {
            auto prev = curr;
            curr->next = new Node(head->val);
            curr = curr->next;
            curr->prev = prev->val == 0 ? NULL : prev;

            if (head->child) {
                curr->next = flatten(head->child);
                curr->next->prev = curr;
            }
            for (; curr->next; curr = curr->next);
        }
        return h->next;
    }
};

// @lc app=leetcode id=430 lang=cpp