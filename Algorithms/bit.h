#pragma once

#include <iostream>
#include <vector>

using namespace std;

class BinaryIndexedTree
{
    vector<int> bit;
    int n;

public:
    BinaryIndexedTree(int _n): n(_n), bit(_n, 0) {}

    int getSum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void add(int i) {
        for (; i < n; i += i & (-i))
            bit[i]++;
    }
};