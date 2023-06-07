var throttle = (fn, t) => {
    let timeout, fnCall = 0;
    return (...args) => {
        const delay = Math.max(0, fnCall - Date.now());
        clearTimeout(timeout);
        timeout = setTimeout(() => {
            fn(...args);
            fnCall = Date.now() + t;
        }, delay);
    }
};