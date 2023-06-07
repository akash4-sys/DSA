var reduce = (nums, fn, k) => {
    for (let i in nums) {
        k = fn (k, nums[i]);
    }
    return k;
};

var reduce = (nums, fn, k) => nums.forEach(n => k = fn(k, n)) || k;