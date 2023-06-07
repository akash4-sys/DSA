// @ memoize any function

function memoize(fn) {
    let memoizedArr = {};
    return function (...args) {
        if (memoizedArr[[...args]] !== undefined)
            return memoizedArr[[...args]];
        return memoizedArr[[...args]] = fn(...args);
    }
}

function memoize(fn) {
    let cache = {};
    return function (...args) {
        let key = JSON.stringify(...args);
        if (key in cache)
            return cache[key];
        return cache[key] = fn(...args);
    }
}