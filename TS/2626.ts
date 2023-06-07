type Fn = (accum: number, curr: number) => number

let reduce = (nums: number[], fn: Fn, k: number): number => {
    for (let i in nums) {
        k = fn (k, nums[i]);
    }
    return k;
}