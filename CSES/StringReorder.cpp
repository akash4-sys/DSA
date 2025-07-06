#include <bits/stdc++.h>
using namespace std;

int fq[26] = {0};
bool possible(int n) {
    for (int i = 0; i < 26; i++)
        if (fq[i] * 2 > n + 1)
            return 0;
    return 1;
}

int main()
{
    string s;
    cin >> s;
    for (char &c : s)
        fq[c - 'A']++;
    
    if (!possible(s.size())) {
        cout << "-1";
        return 0;
    }
    
    for (int i = 0, prev = -1; i < s.size(); i++)
        for (int c = 0; c < 26; c++) {
            if (!fq[c] || prev == c)
                continue;
            fq[c]--;
            if (possible(s.size() - i - 1)) {
                cout << char(c + 'A');
                prev = c;
                break;
            }
            fq[c]++;
        }
    return 0;
}