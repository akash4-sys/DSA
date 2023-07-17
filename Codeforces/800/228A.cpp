#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> st;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    cout << 4 - st.size() << "\n";
    return 0;
}