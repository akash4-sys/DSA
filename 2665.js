const createCounter = (init) => {
    let counter = init;
    const increment = () => ++counter;
    const decrement = () => --counter;
    const reset = () => counter = init;
    return {increment, decrement, reset};
};