#include "../../headers.h"

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &v)
    {
        for (int i = 0; i < v.size(); i++)
            v[0][i] = v[i][i] == '0' ? '1' : '0';
        return v[0];
    }
};


class Solution
{
public:
    string findDifferentBinaryString(vector<string> &v)
    {
        unordered_set<int> st;
        for (auto &s : v)
            st.insert(stoi(s, 0, 2));
        
        for (int i = 0; i < 18; i++)
            if (st.find(i) == st.end())
                return bitset<32>(i).to_string().substr(32 - v.size());
        return "";
    }
};