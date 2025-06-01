#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    for (int f = 0; !q.empty(); f ^= 1) {
        int a = q.front();
        q.pop();
        if (f)
            cout << a << " ";
        else
            q.push(a);
    }
    return 0;
}