#include "headers.h"

class Solution
{
public:
    string largestPalindromic(string num)
    {
        string ans = "", beg = "", rend = "", mid = "";
        map<char, int> umap;

        for (char c : num)
            umap[c]++;

        map<char, int>::reverse_iterator it;
        for (it = umap.rbegin(); it != umap.rend(); it++)
        {
            if (it->second % 2 == 0)
            {
                string temp(it->second / 2, it->first);
                beg += temp;
                rend += temp;
            }
            else if (it->second % 2 != 0)
            {
                int x = it->first - '0';
                int y = (mid != "") ? stoi(mid) : 0;
                mid = to_string(max(x, y));
                int c = it->second - 1;
                string temp(c / 2, it->first);
                beg += temp;
                rend += temp;
            }
        }

        reverse(rend.begin(), rend.end());
        beg += (mid + rend);

        while (*beg.begin() == '0')
        {
            beg.erase(0, 1);
            if (beg.size() == 0)
                break;
            beg.erase(beg.size() - 1, 1);
        }

        if (beg == "")
            beg = "0";
        return beg;
    }
};