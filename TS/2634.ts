function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let filteredArr : number[] = [];
    arr.forEach((x, i) => {
        if (fn(x, i))
            filteredArr.push(x);
    })
    return filteredArr;
};