#include "../../headers.h"

// Time Complexity O(logN)
// Space Complexity O(N)
class MedianFinder
{
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
public:
    MedianFinder() : maxH(){}

    void addNum(int n)
    {
        maxH.push(n);
        minH.push(maxH.top()); 
        maxH.pop();
        if(minH.size() > maxH.size())
            maxH.push(minH.top()), minH.pop();
    }

    double findMedian()
    {
        return maxH.size() > minH.size() ? maxH.top() : (maxH.top() + minH.top()) / 2.0;
    }
};


// Time Complexity O(N)
// Space Complexity O(N)
// TLE
class MedianFinder
{
    vector<int> v;
public:
    MedianFinder() : v(){}

    void addNum(int n)
    {
        int i = 0;
        while(i < v.size() && v[i] < n)
            i++;
        v.push_back(-1);
        while(i < v.size())
            swap(v[i++], n);
    }

    double findMedian()
    {
        if(v.size() % 2)
            return v[v.size() / 2];
        return (float)(v[v.size() / 2] + v[(v.size() / 2) - 1]) / 2;
    }
};


// @lc app=leetcode id=295 lang=cpp