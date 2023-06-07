let promisePool = async (functions, n) => {
    const rec = async () => {
        if (!functions.length)
            return;
        const fn = functions.shift();
        await fn();
        await rec();
    }

    const nPromises = Array(n).fill().map(rec);
    await Promise.all(nPromises);
};


let promisePool2 = async (functions, n) => {
    return new Promise((resolve) => {
        let count = 0, idx = 0;
        let rec = () => {
            if (idx >= functions.length) {
                if (!count)
                    resolve();
                return;
            }

            while (count < n && idx < functions.length) {
                count++;
                const promise = functions[idx++]();
                promise.then(() => {
                    count--;
                    rec();
                });
            }
        };
        rec();
    })
};