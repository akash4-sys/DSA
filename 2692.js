let compose = (arr) => {
    return function (x) {
        for (let i = arr.length - 1; i >= 0; i--)
            x = arr[i](x);
        return x;
    }
};