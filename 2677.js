var chunk = (arr, k) => {
    return Array.from({ length: Math.ceil(arr.length / k) }, function (_, i) {
        return arr.slice(i * k, (i * k) + k);
    });
};

var chunk3 = (arr, k) => {
    let res = [];
    for (let i = 0; i < arr.length; i += k)
        res.push(arr.slice(i, i + k));
    return res;
};

var chunk2 = (arr, k) => {
    let res = [];
    for (let i = 0, it = 0; i < arr.length; it++) {
        res.push([]);
        for (let j = i; i < Math.min(j + k, arr.length); i++)
            res[it].push(arr[i]);
    }
    return res;
};