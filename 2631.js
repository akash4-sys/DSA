Array.prototype.groupBy = function (fn) {
    let res = {};
    for (let x of this) {
        let key = fn(x);
        if (key in res)
            res[key].push(x);
        else
            res[key] = [x];
    }
    return res;
};