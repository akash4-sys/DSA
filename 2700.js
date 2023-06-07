let objDiff = (a, b) => {
    if (a === b)
        return {};
    if (a === null || b === null)
        return [a, b]
    if (typeof a != 'object' || typeof b != 'object')
        return [a, b];
    if (Array.isArray(a) !== Array.isArray(b))
        return [a, b];

    const res = {};
    for (const key in a) {
        if (key in b) {
            const diff = objDiff(a[key], b[key]);
            if (Object.keys(diff).length)
                res[key] = diff;
        }
    }
    return res;
};