#include "../../headers.h"

class MyStack
{
    queue<int> q;
public:
    MyStack(): q() {}

    void push(int x)
    {
        q.push(x);
    }

    void push(int x)
    {
        q.push(x);
        for(int i = 1; i < q.size(); i++)
            q.push(q.front()), q.pop();
    }

    int pop()
    {
        int x;
        queue<int> t;
        while(q.size() > 1)
            x = q.front(), t.push(x), q.pop();
        x = q.front();
        q = t;
        return x;
    }

    int top()
    {
        int x;
        queue<int> t;
        while(q.size())
            x = q.front(), t.push(x), q.pop();
        q = t;
        return x;
    }

    bool empty()
    {
        return q.empty();
    }
};


// @lc app=leetcode id=225 lang=cpp