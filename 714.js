var maxProfit = function (p, fee) {
    let ans = Array(2).fill().map(() => Array(2).fill(0));
    for(let i = p.length - 1; i >= 0; i--){
        for(let buy = 0; buy <= 1; buy++){
            if(buy)
            ans[i % 2][buy] = Math.max(-fee - p[i] + ans[(i + 1) % 2][0], 0 + ans[(i + 1) % 2][0]);
            else
            ans[i % 2][buy] = Math.max(p[i] + ans[(i + 1) % 2][1], 0 + ans[(i + 1) % 2][1]);
        }
    }
    return ans[0][1];
};