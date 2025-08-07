#pragma once
#include <vector>
using namespace std;

/*  Heavy Light Decomposition algorithm is used to answer the queries of the type where you need to find some associative
    value in path between two nodes. Idea is to create heavy and light edges. Then for each heavy path we will use segment
    tree to query for the desired property. HLD just lable the nodes, main computation is handled by simple segment tree.

    heavy: heavy[u] = v means that edge from u to v means node v has largest substree in all children of u
    head: points to the start of heavy path for each node
    idx: stores the index of nodes when heavy edges are explored first, idea is to make each heavy path consecutive so that
        segment tree can query upon them
    
    Here Segment tree can be separated class but that will mean extra log(n) in decompose function
    Time Complexity: O(N + Q*log^2(n))
*/

vector<int> a;
vector<vector<int>> g;

class HLD
{
    int n, pos = 0;
    vector<int> depth, idx, heavy, head, segTree, par;

    void segBuild() {
        for (int i = n - 1; i > 0; i--)
            segTree[i] = max(segTree[2 * i], segTree[2 * i + 1]);
    }
 
    int segQuery(int l, int r) {
        int ans = 0;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1)
                ans = max(ans, segTree[l++]);
            if (r & 1)
                ans = max(ans, segTree[--r]);
        }
        return ans;
    }
 
    int dfs(int u) 
    {
        int treeSize = 1, mxSubSize = 0;
        for (int &v : g[u])
            if (v != par[u])
            {
                par[v] = u;
                depth[v] = depth[u] + 1;
                int subSize = dfs(v);
                treeSize += subSize;
                if (subSize > mxSubSize)
                    mxSubSize = subSize, heavy[u] = v;
            }
        return treeSize;
    }
 
    void decompose(int u, int h)
    {
        head[u] = h;
        segTree[pos + n] = a[u];
        idx[u] = pos++;
        if (heavy[u] != -1)
            decompose(heavy[u], h);
 
        for (int v : g[u])
            if (v != par[u] && v != heavy[u])
                decompose(v, v);
    }
 
public:
    HLD(int N): n(N), idx(n), par(n, 0), depth(n), heavy(n, -1), head(n) {
        segTree.resize(n * 2 + 1, 0);
        dfs(0);
        decompose(0, 0);
        segBuild();
    }
 
    void segUpdate(int u, int val) {
        int i = idx[u] + n;
        segTree[i] = val;
        while (i > 1) {
            i /= 2;
            segTree[i] = max(segTree[2 * i], segTree[2 * i + 1]);
        }
    }
 
    int query(int u, int v) {
        int res = 0;
        for (; head[u] != head[v]; v = par[head[v]]) {
            if (depth[head[u]] > depth[head[v]])
                swap(u, v);
            res = max(res, segQuery(idx[head[v]], idx[v]));
        }
        
        if (depth[u] > depth[v])
            swap(u, v);
        return max(res, segQuery(idx[u], idx[v]));
    }
};