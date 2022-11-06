#include "headers.h"

class Solution
{
public:
    vector<int> applyOperations(vector<int> &v)
    {
        for(int i = 0; i < v.size() - 1; i++)
            if(v[i] == v[i + 1])
                v[i] *= 2, v[i + 1] = 0;
        int i = 0;
        for(auto n: v)
            if(n != 0) v[i++] = n;
        while(i < v.size()) 
            v[i++] = 0;
        return v;
    }
};



class Solution
{
public:
    vector<int> applyOperations(vector<int> &v)
    {
        vector<int> ans;
        int z = 0;
        for(int i = 0; i < v.size() - 1; i++)
            if(v[i] == v[i + 1])
                v[i] *= 2, v[i + 1] = 0;
        for(int n: v)
            if(n) ans.push_back(n);
            else z++;
        while(z--)
            ans.push_back(0);
        return ans;
    }
};