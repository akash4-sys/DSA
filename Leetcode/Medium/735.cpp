#include "../../headers.h"

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &v)
    {
        vector<int> s;
        for (int n : v)
        {
            bool destroyed = 0;
            while (s.size() && s.back() > 0 && n < 0 && !destroyed) {
                if (s.back() >= -n)
                    destroyed = 1;
                if (s.back() <= -n)
                    s.pop_back();
            }
            if (!destroyed)
                s.push_back(n);
        }
        return s;
    }
};


class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &v)
    {
        vector<int> s;
        auto neq = [&](int x, int y) { return x >= 0 && y < 0; };
        for (int n : v)
        {
            while (!s.empty() && neq(s.back(), n) && s.back() < -n)
                s.pop_back();
            if (!s.empty() && neq(s.back(), n) && s.back() == -n) {
                s.pop_back();
                continue;
            }
            if (!s.empty() && neq(s.back(), n) && s.back() > -n)
                continue;
            s.push_back(n);
        }
        return s;
    }
};

// @lc app=leetcode id=735 lang=cpp