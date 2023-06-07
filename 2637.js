var timeLimit = (fn, t) => {
    return async (...args) => {
        return new Promise((resolve, reject) => {
            setTimeout(() => reject("Time Limit Exceeded"), t);
            fn(...args).then(resolve).catch(reject)
                .finally(() => clearTimeout(timeout));
        })
    }
};

var timeLimit2 = (fn, t) => {
    return async (...args) => {
        const timeLimitPromise = new Promise((resolve, reject) => {
            setTimeout(() => reject("Time Limit Exceeded"), t);
        });
        const returnedPromise = fn(...args);
        return Promise.race([timeLimitPromise, returnedPromise]);
    }
}

var timeLimit3 = (fn, t) => {
    return async (...args) => {
        return new Promise(async (resolve, reject) => {
            const timeout = setTimeout(() => {
                reject("Time Limit Exceeded");
            }, t);

            try {
                resolve(await fn(...args));
            } catch (err) {
                reject(err);
            }
            clearTimeout(timeout);
        });
    }
}