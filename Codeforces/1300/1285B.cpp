#include <iostream>
#include <vector>

using namespace std;

string solve()
{
    int n;
    cin >> n;
    long long lsum = 0, rsum = 0;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 0; i < n; i++)
    {
        lsum += v[i], rsum += v[n - i - 1];
        if (lsum <= 0 || rsum <= 0)
            return "NO";
    }
    return "YES";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}