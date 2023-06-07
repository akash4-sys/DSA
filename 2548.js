var fibGenerator = function* () {
    let curr = 0, next = 1;
    while (1) {
        yield curr;
        let temp = curr;
        curr = next;
        next += temp;
    }
};

var fibGenerator = function* (curr = 0, next = 1) {
    yield curr;
    yield *fibGenerator(next, curr + next);
};