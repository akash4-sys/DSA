#include "../../headers.h"

#define ll long long

class SegmentTree
{
    ll n;
    vector<ll> tree;

public:
    SegmentTree(int n) {
        this->n = n;
        tree = vector<ll>(n * 4, 0);
    }

    ll update(int idx, ll val, int i = 1, int left = 0, int right = -1)
    {
        if (right == -1)
            right = n - 1;
        if (idx < left || idx > right)
            return 0;
        if (left == right) {
            tree[i] += val;
            return tree[i];
        }

        ll mid = left + (right - left) / 2;
        update(idx, val, i * 2, left, mid);
        update(idx, val, (i * 2) + 1, mid + 1, right);
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
};

class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int> &a, vector<int> &v)
    {
        vector<long long> ans(v.size(), 0);
        SegmentTree tree(1e5 + 1);
        for (int i = 0; i < v.size(); i++)
            ans[i] = tree.update(a[i], v[i]);
        return ans;
    }
};


class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int>& v, vector<int>& fq)
    {
        unordered_map<int, long long> freq;
        map<long long, int> freq_map;
        vector<long long> ans(v.size(), 0);
        for (int i = 0; i < v.size(); i++)
        {
            if (freq_map[freq[v[i]]]) {
                if (--freq_map[freq[v[i]]] == 0)
                    freq_map.erase(freq[v[i]]);
            }

            freq[v[i]] += fq[i];
            freq_map[freq[v[i]]]++;
            ans[i] = freq_map.rbegin()->first;
        }
        return ans;
    }
};