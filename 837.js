let new21Game = (n, k, maxPts) => {
    let dp = {};
    let dfs = (score) => {
        if (score >= k)
            return score <= n;
        if (score in dp)
            return dp[score];
        
        let prob = 0;
        for (let i = 1; i <= maxPts; i++)
            prob += dfs(score + i);
        
        return dp[score] = (prob / maxPts).toPrecision(5);
    }
    return dfs(0);
};