#include "../../headers.h"

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *node = head;
        while(node)
        {
            Node *temp = node->next;
            node->next = new Node(node->val);
            node->next->next = temp;
            node = temp;
        }

        node = head;
        while(node)
        {
            if(node->random)
                node->next->random = node->random->next;
            node = node->next->next;
        }

        Node *ans = new Node(0), *h = ans;

        while(head)
        {
            h->next = head->next;
            h = h->next;

            head->next = head->next->next;
            head = head->next;
        }

        return ans->next;
    }
};