#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < pow(2, n); i++)
    {
        bitset<32> bt(i ^ (i >> 1));
        string s = bt.to_string();
        cout << s.substr(32 - n) << "\n";
    }
    return 0;
}