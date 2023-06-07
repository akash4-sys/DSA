type F = (...args: any[]) => any

var debounce = (fn : F, t : number) => {
    let timer : ReturnType<typeof setTimeout>;
    return (...props : any) => {
        clearTimeout(timer);
        timer = setTimeout(() => fn(...props), t);
    }
}