#include "headers.h"

class LUPrefix
{
    int i = 1;
    vector<int> v;
public:
    LUPrefix(int n) {
        v.resize(n + 1, 0);
    }

    void upload(int i) {
        v[i] = 1;
    }

    int longest()
    {
        while (i < v.size() && v[i])
            i++;
        return i - 1;
    }
};