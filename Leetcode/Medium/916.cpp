#include "../../headers.h"

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int target[26];

        for(string s : words2)
        {
            int count[26];
            for(char c: s)
                count[c - 'a']++;
            for(int i = 0; i < 26; i++)
                target[i] = max(target[i], count[i]);
        }

        for(int i = 0; i < words1.size(); i++)
        {
            int count[26];
            for(char c : words1[i])
                count[c - 'a']++;
            
            bool check = true;
            for(int j=0; j < 26 && check; j++)
                check = count[j] >= target[j]; 

            if(check)
                ans.push_back(words1[i]);
        }
        
        return ans;
    }
};