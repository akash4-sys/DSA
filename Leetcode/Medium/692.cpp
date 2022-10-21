#include "../../headers.h"

class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> mp;
        for(string w: words)
            mp[w]++;

        auto comp = [&](auto &a, auto &b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> cpq;
        cpq pq(comp);

        for(auto &[w, f]: mp)
        {
            pq.push({w, f});
            if(pq.size() > k)
                pq.pop();
        }

        vector<string> ans;
        while(!pq.empty())
            ans.push_back(pq.top().first), pq.pop();
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};