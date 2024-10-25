#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

class WaveletTree {
public:
    int low, high;
    WaveletTree* left;
    WaveletTree* right;
    vector<int> freq;

    WaveletTree(vector<int>::iterator from, vector<int>::iterator to, int low, int high) 
        : low(low), high(high) {
        if (from >= to || low == high) {
            return;
        }
        
        int mid = (low + high) / 2;
        freq.reserve(to - from + 1);
        freq.push_back(0);
        
        for (auto it = from; it != to; ++it) {
            freq.push_back(freq.back() + (*it <= mid));
        }
        
        auto pivot = stable_partition(from, to, [=](int x) { return x <= mid; });
        left = new WaveletTree(from, pivot, low, mid);
        right = new WaveletTree(pivot, to, mid + 1, high);
    }

    int kth(int l, int r, int k) {
        if (l > r) return -1;
        if (low == high) return low;

        int inLeft = freq[r] - freq[l - 1];
        int mid = (low + high) / 2;

        if (k <= inLeft) {
            return left->kth(freq[l - 1] + 1, freq[r], k);
        } else {
            return right->kth(l - freq[l - 1], r - freq[r], k - inLeft);
        }
    }
};

int solve()
{
    int n = II, m = II, ans = n + 1;
    vector<int> a(n + 1, n + 1);
    vector<vector<int>> segs;
    while (m--)
        segs.push_back({II, II});
    
    for (int i = 1, q = II; i < q; i++)
        a[II] = i;
    
    WaveletTree tree(all(a), 1, n);
    for (auto &seg : segs) {
        int l = seg[0], r = seg[1], k = (r - l + 1) / 2 + 1;
        ans = min(ans, tree.kth(l, r, k));
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}