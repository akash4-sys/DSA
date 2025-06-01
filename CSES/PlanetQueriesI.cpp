#include <bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
 
class TreeAncestor
{
    int n, maxDepth = 30;
    vector<vector<int>> ancestor;
public:
    TreeAncestor(int n, vector<int> &child)
    {
        this->n = n;
        ancestor = vector(n, vector<int>(maxDepth, -1));
 
        for (int i = 0; i < n; i++)
            ancestor[i][0] = child[i];
 
        for (int j = 1; j < maxDepth; j++)
            for (int i = 0; i < n; i++)
                if (ancestor[i][j - 1] != -1)
                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    }
 
    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < maxDepth; i++)
            if (k & (1 << i)) {
                node = ancestor[node][i];
                if (node == -1) return node;
            }
        return node;
    }
};
 
int main()
{
    fast;
    int n = II, q = II;
    vector<int> child(n);
    for (int &c : child)
        c = II - 1;
    TreeAncestor tree(n, child);
 
    while (q--)
        cout << tree.getKthAncestor(II - 1, II) + 1 << "\n";
    return 0;
}