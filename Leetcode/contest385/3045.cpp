#include "../../headers.h"

// Rolling Hash solution

class Solution
{
public:
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        long long ans = 0, mod = 1e17 + 3;
        map<long long, long long> mp;
        for (auto &s : words)
        {
            long long prefix_hash = 0, suffix_hash = 0, pow = 1;
            for (int n = s.size(), i = 0; i < n; i++)
            {
                prefix_hash = (prefix_hash * 27LL + (1LL + s[i] - 'a')) % mod;
                suffix_hash = (((1LL + s[n - i - 1] - 'a') * pow) % mod + suffix_hash) % mod;
                pow = (pow * 27) % mod;
                if (prefix_hash == suffix_hash && mp.count(prefix_hash))
                    ans += mp[prefix_hash];
            }
            mp[prefix_hash]++;
        }
        return ans;
    }
};


// Hashing improves time complexity significantly

class Solution
{
    vector<int> zAlgo(string &s)
    {
        int n = s.size(), x = 0, y = 0;
        vector<int> zArray(n);
        zArray[0] = n;
        for (int i = 1; i < n; i++)
        {
            zArray[i] = max(0, min(zArray[i - x], y - i + 1));
            while (i + zArray[i] < n && s[zArray[i]] == s[i + zArray[i]])
                x = i, y = i + zArray[i], zArray[i]++;
        }
        return zArray;
    }

public:
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        long long ans = 0, mod = 1e17 + 3;      // random large prime number
        map<long long, long long> mp;
        for (auto &s : words)
        {
            auto zArray = zAlgo(s);
            long long hash = 0;
            for (int n = s.size(), i = 0; i < n; i++)
            {
                hash = (hash * 27LL + (1LL + s[i] - 'a')) % mod;    // hashing
                if (zArray[n - i - 1] == i + 1 && mp.count(hash))
                    ans += mp[hash];
            }
            mp[hash]++;
        }
        return ans;
    }
};


// @ Although this sol is accepted it can very well fail coz
// @ using string as a key is slow
// Time Complexity - O(N), where N is total length array + string
// Space Complexity - O(N)

class Solution
{
    vector<int> zAlgo(string &s)
    {
        int n = s.size(), x = 0, y = 0;
        vector<int> zArray(n);
        for (int i = 1; i < n; i++)
        {
            zArray[i] = max(0, min(zArray[i - x], y - i + 1));
            while (i + zArray[i] < n && s[zArray[i]] == s[i + zArray[i]])
                x = i, y = i + zArray[i], zArray[i]++;
        }
        return zArray;
    }

public:
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        long long ans = 0;
        map<string, long long> mp;
        for (auto &s : words)
        {
            auto zArray = zAlgo(s);
            zArray[0] = s.size();
            string r = "";
            for (int n = s.size(), i = 0; i < n; i++)
            {
                r += s[i];
                if (zArray[n - i - 1] == i + 1 && mp.count(r))
                    ans += mp[r];
            }
            mp[s]++;
        }
        return ans;
    }
};