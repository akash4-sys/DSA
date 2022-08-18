#include "../../headers.h"

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        set<string> codes;
        for (string s : words)
        {
            string r = "";
            for (char c : s)
                r += morse[c - '0' - 49];
            codes.insert(r);
        }
        return codes.size();
    }
};