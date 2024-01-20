#pragma once

#include <vector>

using namespace std;

// For classic implementation check problem 912
// @ Ref - https://en.cppreference.com/w/cpp/algorithm/inplace_merge

// Time Complexity - O(NlogN)
// Space Compleixty - O(N)

class MergeSort {
    void mergeSort(auto begin, auto end) {
        if (end - begin <= 1)
            return;

        auto mid = begin + (end - begin) / 2;
        mergeSort(begin, mid);
        mergeSort(mid, end);
        inplace_merge(begin, mid, end);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums.begin(), nums.end());
        return nums;
    }
};