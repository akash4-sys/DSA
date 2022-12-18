#include "../../headers.h"

class MyQueue
{
    stack<int> st, q;
    int del = 0;
public:
    MyQueue(): st(), q() {}

    void push(int x)
    {
        st.push(x);
        q = stack<int>();
        stack<int> t = st;
        while(t.size() > del)
            q.push(t.top()), t.pop();
    }

    int pop()
    {
        int x = q.top();
        q.pop();
        del++;
        return x;
    }

    int peek()
    {
        return q.top();
    }

    bool empty()
    {
        return q.empty();
    }
};


// @lc app=leetcode id=232 lang=cpp