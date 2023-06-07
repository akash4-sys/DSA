var debounce = (fn, t) => {
    let timer;
    return (...args) => {
        timer = setTimeout(() => fn(...args), t);
        clearTimeout(timer);
    }
};