#include "headers.h"

class Allocator
{
    int n;
    vector<int> v;

public:
    Allocator(int n)
    {
        this->n = n;
        v = vector<int>(n, 0);
    }

    int allocate(int sz, int id)
    {
        int it = -1, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (!v[i])
            {
                if(c == 0)
                    it = i;
                c++;
                if(c >= sz)
                {
                    for(int j = 0; j < c; j++)
                        v[it + j] = id;
                    return it;
                }
            }
            else
                it = -1, c = 0;
        }
        return -1;
    }

    int free(int id)
    {
        int a = 0;
        for (int i = 0; i < n; i++)
            if (v[i] == id)
                v[i] = 0, a++;
        return a;
    }
};