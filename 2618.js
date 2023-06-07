var checkIfInstanceOf = (obj, classFunction) => {
    if (obj === null || obj === undefined || typeof classFunction !== "function")
        return false;

    let prot = Object.getPrototypeOf(obj);
    while (prot !== null) {
        if (prot === classFunction.prototype)
            return true;
        prot = Object.getPrototypeOf(prot);
    }
    return false;
};