#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class TrieNode {
    public:
    TrieNode *child[26];
    bool isEnd;
};

int main()
{
    fast;
    string s, word;
    int n, MOD = 1e9 + 7;
    cin >> s >> n;

    TrieNode *root = new TrieNode();
    auto insert = [&](string &word) {
        TrieNode *node = root;
        for (auto c : word)
        {
            if (!node->child[c - 'a'])
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->isEnd = 1;
    };

    for (int i = 0; i < n; i++) {
        cin >> word;
        reverse(word.begin(), word.end());
        insert(word);
    }
    
    int m = s.length();
    reverse(s.begin(), s.end());
    vector<int> dp(m, 0);
    
    for (int i = 0; i < m; i++) {
        TrieNode *node = root;
        for (int j = i; j < m; j++)
        {
            if (!node->child[s[j] - 'a'])
                break;
            node = node->child[s[j] - 'a'];
            if (node->isEnd) {
                if (i)
                    dp[j] = (dp[j] + dp[i - 1]) % MOD;
                else
                    dp[j] = (dp[j] + 1) % MOD;
            }
        }
    }
    
    cout << dp[m - 1] % MOD << endl;
    return 0;
}