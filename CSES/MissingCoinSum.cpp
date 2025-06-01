#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &a : v)
        cin >> a;
    sort(v.begin(), v.end());
    
    long long sum = 1;
    for (int &a : v) {
        if (sum < a)
            break;
        sum += a;
    }
    cout << sum;
    return 0;
}