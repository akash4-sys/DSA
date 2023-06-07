var inorderTraversal = function* (mat) {
    if (!Array.isArray(mat)) {
        yield mat;
        return;
    }
    for (let ele of mat)
        yield *inorderTraversal(ele);
};

var inorderTraversal = function* (mat) {
    yield* arr.flat(Infinity);
};