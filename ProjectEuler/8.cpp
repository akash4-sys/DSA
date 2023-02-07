#include "../headers.h"

long long window (string &r)
{
    long long mul = 1;
    for (int i = 0; i <= 13; i++)
        mul = (mul * (long long)(r[i] - '0'));
}

long long Mul13(string &s)
{
    string w = s.substr(0, 13);
    long long ans = window(w);
    for (int i = 1; i < s.size(); i++)
    {
        w.erase(s.begin()), w += s[i + 1];
        ans = max(ans, window(w));
    }
    return ans;
}

int main()
{
    string s;
    cout<<Mul13(s)<<endl;
    return 0;
}