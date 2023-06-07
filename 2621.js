// @Promise

let sleep = async (ms) => {
    return new Promise(resolve => {
        setTimeout(resolve, ms);
    });
}