// JSON.tostringify();

var jsonStringify = (object) => {
    if (object === null)
        return "null";
    if (typeof object === 'string')
        return `"${object}"`;
    if (typeof object !== 'object')
        return object.toString();

    if (Array.isArray(object)) {
        let res = "";
        for (let i = 0; i < object.length; i++)
            res += jsonStringify(object[i]) + ",";
        return "[" + res.substring(0, res.length - 1) + "]";
    }

    let res = '';
    for (const key in object)
        res += `${jsonStringify(key)}:${jsonStringify(object[key])},`;
    return "{" + res.substring(0, res.length - 1) + "}";
};