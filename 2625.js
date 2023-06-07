var flat = (nums, k) => {
    let res = [];
    let flatten = (arr, n) => {
        for (let x of arr) {
            if (Array.isArray(x) && n > 0)
                flatten(x, n - 1);
            else
                res.push(x);
        }
    }

    flatten(nums, k);
    return res;
};