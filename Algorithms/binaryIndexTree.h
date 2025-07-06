#pragma once

#include <iostream>
#include <vector>

using namespace std;

//! 1-idx is necessary, with 0 idx it fails sometimes

class BIT
{
    int n;
    vector<int> bit;
public:
    BIT(int N): n(N + 1), bit(N + 1, 0) {}

    int getSum(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void add(int i, int val) {
        for (++i; i < n; i += i & (-i))
            bit[i] += val;
    }
};