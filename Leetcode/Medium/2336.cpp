#include "../../headers.h"

class SmallestInfiniteSet
{
    int it = 1;
    set<int> st;
public:
    SmallestInfiniteSet() {}

    int popSmallest()
    {
        if (st.empty())
            return it++;
        int n = *st.begin();
        st.erase(st.begin());
        return n;
    }

    void addBack(int n)
    {
        if (n < it)
            st.insert(n);
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class SmallestInfiniteSet
{
    set<int> st;
public:
    SmallestInfiniteSet()
    {
        vector<int> v(1001);
        iota(v.begin(), v.end(), 1);
        st = set<int>(v.begin(), v.end());
    }

    int popSmallest()
    {
        int n = *st.begin();
        st.erase(st.begin());
        return n;
    }

    void addBack(int n)
    {
        st.insert(n);
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class SmallestInfiniteSet
{
    vector<int> st;
    int it;
public:
    SmallestInfiniteSet() : it(1)
    {
        st = vector<int>(1002, 1);
    }

    int popSmallest()
    {
        for (int i = it; i < 1002; i++)
            if (st[i])
            {
                st[i] = 0; 
                return i;
            }
        return -1;
    }

    void addBack(int n)
    {
        st[n] = 1;
        if (n < it)
            it = n;
    }
};