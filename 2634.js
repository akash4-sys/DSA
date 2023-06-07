let filter = (arr, fn) => {
    return arr.flatMap((x, i) => fn(x, i) ? [x] : []);
};

let filter = (arr, fn) => {
    let filteredArr = [];
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i))
            filteredArr.push(arr[i]);
        }
        return filteredArr;
    };
    

let filter = (arr, fn) => {
    let filteredArr = [];
    arr.forEach((x, i) => {
        if (fn(x, i))
            filteredArr.push(x);
    })
    return filteredArr;
};