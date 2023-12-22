#include "../../headers.h"

class Solution
{
public:
    bool equalFrequency(string s)
    {
        int ch[26] = {0};
        for (char &c : s)
            ch[c - 'a']++;

        for (int i = 0; i < 26; i++)
            if (ch[i])
            {
                ch[i]--;
                unordered_set<int> st;
                for (int j = 0; j < 26; j++)
                    if (ch[j])
                        st.insert(ch[j]);
                if (st.size() == 1)
                    return 1;
                ch[i]++;
            }
        return 0;
    }
};