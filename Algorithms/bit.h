#pragma once

#include <iostream>
#include <vector>

using namespace std;

//! 1-idx is necessary, with 0 idx it fails sometimes

class BinaryIndexedTree
{
    vector<int> bit;
    int n;

public:
    BinaryIndexedTree(int _n): n(_n + 1), bit(_n + 1, 0) {}

    int getSum(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void add(int i) {
        for (++i; i < n; i += i & (-i))
            bit[i]++;
    }
};