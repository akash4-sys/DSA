var TimeLimitedCache = function() {
    this.dict = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const val = this.dict.get(key);
    if (val) 
        clearTimeout(val.timeout);
    const timeout = setTimeout(() => this.dict.delete(key), duration);
    this.dict.set(key, {value, timeout});
    return Boolean(val);
};

TimeLimitedCache.prototype.get = function(key) {
    return this.dict.has(key) ? this.dict.get(key).value : -1;
};

TimeLimitedCache.prototype.count = function() {
    return this.dict.size;
};