#include "../../headers.h"

class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiou";
        int cnt = 0;
        for (int i = 0; i < s.size() / 2; i++)
            cnt += vowels.find(tolower(s[i])) != string::npos;
        for (int i = s.size() / 2; i < s.size(); i++)
            cnt -= vowels.find(tolower(s[i])) != string::npos;
        return !cnt;
    }
};