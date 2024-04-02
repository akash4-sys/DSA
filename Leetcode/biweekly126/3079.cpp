#include "../../headers.h"

class Solution
{
public:
    int sumOfEncryptedInt(vector<int> &v)
    {
        int sum = 0;
        for (int a : v)
        {
            string s = to_string(a);
            char c = *max_element(s.begin(), s.end());
            sum += stoi(string(s.size(), c));
        }
        return sum;
    }
};