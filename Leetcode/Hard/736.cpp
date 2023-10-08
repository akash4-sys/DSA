#include "../../headers.h"

class Solution
{
    int rec(stringstream &ss, string s, unordered_map<string, int> tokens = {})
    {
        while (s.back() == ')')
            s.pop_back();
        if (s.empty())
            return 0;
        if (tokens.count(s))
            return tokens[s];
        if (s[0] != '(')
            return stoi(s);

        if (s == "(let")
        {
            unordered_map<string, int> mp;
            string token = "";
            while (ss >> s)
            {
                if (s.back() == ')')
                    return rec(ss, s, mp);
                if (token.empty())
                    token = s;
                else
                    mp[token] = rec(ss, s, mp), token = "";
            }
        }
        else if (s == "(add")
        {
            ss >> s;
            return rec(ss, s, tokens) + rec(ss, s, tokens);
        }
        ss >> s;
        return rec(ss, s, tokens) * rec(ss, s, tokens);
    }

public:
    int evaluate(string exp)
    {
        stringstream ss(exp);
        string s;
        ss >> s;
        return rec(ss, s);
    }
};