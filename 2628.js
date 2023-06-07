var areDeeplyEqual = (o1, o2) => {
    if (o1 === o2)
        return true;
    if (String(o1) !== String(o2) || o1 === null || o2 === null)
        return false;
    if (typeof o1 !== 'object')
        return o1 === o2;
    
    let result = 1;
    if (Array.isArray(o1)) {
        if (o1.length !== o2.length)
            return false;
        
        for (let i = 0; i < o1.length; i++)
            result &= areDeeplyEqual(o1[i], o2[i]);
        return result;
    }
    
    if (Object.keys(o1).length !== Object.keys(o2).length)
        return false;
    
    for (const key in o1)
        result &= areDeeplyEqual(o1[key], o2[key]);
    return result;
};