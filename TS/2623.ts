type Fn = (...params: any) => any;

interface CacheInf {
    [key : string] : number
}

let memoize = (fn: Fn): Fn => {
    let cache: CacheInf = {};
    return (...args: number[]): number => {
        let key = JSON.stringify(args);
        if (key in cache)
            return cache[key];
        return cache[key] = fn(...args);
    }
}