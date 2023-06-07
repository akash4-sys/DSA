type Fn = (...params: any[]) => Promise<any>;

const timeLimit = (fn: Fn, t: number): Fn => {
    return async (...args) => {
        const timeLimitPromise = new Promise((resolve, reject) => {
            setTimeout(() => reject("Time Limit Exceeded"), t);
        });
        const returnedPromise = fn(...args);
        return Promise.race([timeLimitPromise, returnedPromise]);
    }
}