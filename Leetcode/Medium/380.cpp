#include "../../headers.h"

class RandomizedSet {
    unordered_set<int> st;

    // overkill function
    float randf(float lo, float hi) {
        float random = ((float) rand()) / (float) RAND_MAX;
        float diff = hi - lo;
        float r = random * diff;
        return lo + r;
    }

    int randomIndex(int lo, int hi) {
        int n = hi - lo + 1;
        int i = rand() % n;
        if (i < 0) i = -i;
        return lo + i;
    }

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (st.count(val))
            return 0;
        st.insert(val);
        return 1;
    }
    
    bool remove(int val) {
        if (!st.count(val))
            return 0;
        st.erase(val);
        return 1;
    }
    
    int getRandom() {
        int n = st.size(), i = rand() % n;
        auto it = st.begin();
        advance(it, i);
        return *it;
    }
};

class RandomizedSet
{
    unordered_map<int, int> ump;
    vector<int> v;
public:
    RandomizedSet() {}

    bool insert(int n)
    {
        int p = ump.count(n) ? !ump[n] : 1;
        ump[n] = 1;
        v.push_back(n);
        return p;
    }

    bool remove(int n)
    {
        int p = ump.count(n) ? ump[n] : 0;
        ump[n] = 0;
        return p;
    }

    int getRandom()
    {
        while(1)
        {
            int i = rand() % v.size();
            if(ump[v[i]])
                return v[i];
        }
    }
};


// @lc app=leetcode id=380 lang=cpp