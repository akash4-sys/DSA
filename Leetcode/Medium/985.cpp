#include "../../headers.h"

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &v, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int sum = accumulate(begin(v), end(v), 0, [](int s, int a){ 
            return s + (a % 2 == 0 ? a : 0);
        });
        for(auto &q: queries)
        {
            if(v[q[1]] % 2 == 0)
                sum -= v[q[1]];
            v[q[1]] += q[0];
            if(v[q[1]] % 2 == 0)
                sum += v[q[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &v, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int even = 0;
        for(int n: v)
            if(n % 2 == 0)
                even += n;
        
        for(auto q: queries)
        {
            int org = v[q[1]];
            int curr = v[q[1]] += q[0];
            if(org % 2 == 0 && curr % 2 == 0)
                even += q[0];
            else if(org % 2 != 0 && curr % 2 == 0)
                even += curr;
            else if(org % 2 == 0 && curr % 2 != 0)
                even -= org;
            ans.push_back(even);
        }
        return ans;
    }
};