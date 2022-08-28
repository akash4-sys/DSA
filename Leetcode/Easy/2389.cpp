#include "headers.h"

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(begin(nums), end(nums));
        partial_sum(begin(nums), end(nums), begin(nums));
        transform(begin(queries), end(queries), begin(queries), [&](int q)
                  { return upper_bound(begin(nums), end(nums), q) - begin(nums); });
        return queries;
    }
};