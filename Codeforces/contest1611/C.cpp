#include <bits/stdc++.h>

using namespace std;

#define deq deque<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void print(deq d) {
    while (d.size()) {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << "\n";
}

deq calc(deq dq) {
    deq p;
    while (dq.size())
        if (dq.front() <= dq.back())
            p.push_front(dq.front()), dq.pop_front();
        else
            p.push_back(dq.back()), dq.pop_back();
    return p;
}

void f(deq &dq) {
    int x = dq.front();
    dq.pop_front();
    dq.push_back(x);
}

deq solve()
{
    int n = II;
    deq a;
    for (int i = 0; i < n; i++)
        a.push_back(II);
    
    auto p = calc(a);
    auto a1 = calc(p);
    if (a == a1)
        return p;

    f(a1);
    if (a == a1)
        return p;
    
    f(p);
    auto a2 = calc(p);
    if (a == a2)
        return p;

    f(a2);
    if (a == a2)
        return p;
    return {-1};
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        print(solve());
    return 0;
}