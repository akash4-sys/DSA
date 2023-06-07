var jsonToMatrix = (arr) => {
    const isObject = x => (x !== null && typeof x == 'object');

    const getKeys = (obj) => {
        if (!isObject(obj))
            return [''];
        
        const result = [];
        for (const key in obj) {
            const childKeys = getKeys(obj[key]);
            for (const chKey of childKeys)
                result.push(chKey ? `${key}.${chKey}` : key);
        }
        return result;
    }

    const keysSet = arr.reduce((acc, curr) => {
        getKeys(curr).forEach(key => acc.add(key));
        return acc;
    }, new Set());

    const keys = Array.from(keysSet).sort();

    const getValue = (obj, paths) => {
        const path = paths.split('.');
        let i = 0, value = obj;

        while (i < path.length) {
            if (!isObject(value))
                break;
            value = value[path[i++]];
        }

        if (i < path.length || isObject(value) || value === undefined)
            return '';
        return value;
    }

    const mat = [keys];
    arr.forEach(obj => {
        mat.push(keys.map(key => getValue(obj, key)));
    })
    return mat;
};