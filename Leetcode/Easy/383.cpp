#include "../../headers.h"

class Solution
{
public:
    bool canConstruct(string ran, string mag)
    {
        unordered_map<char, int> ump;
        for(char c: mag)
            ump[c]++;
        
        for(char r: ran)
        {
            if(ump[r] == 0)
                return false;
            ump[r]--;
        }
        return true;
    }
};


// Without umap
class Solution
{
public:
    bool canConstruct(string ran, string mag)
    {
        int ump[26] = {0};
        for(char c: mag)
            ump[c - 'a']++;
        
        for(char r: ran)
        {
            if(ump[r - 'a']-- == 0)
                return false;
        }
        return true;
    }
};