["Awesome substring solver"](https://leetcode.com/problems/minimum-window-substring/discuss/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems)

For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions. A general way is to use a hashmap assisted with two pointers. The template is given below.

```
int findSubstring(string s){
vector<int> map(128,0);
int counter; // check whether the substring is valid
int begin=0, end=0; //two pointers, one point to tail and one head
int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){

                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again

                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }

            /* update d here if finding maximum*/
        }
        return d;

}
```

<!-- @ Important note related to bitwise -->

binary representation of a number x
let x = 9

so 9 is 2^3 + 1

1 0 0 1

---

2^3 2^2 2^1 2^0

## [Subarrays](https://leetcode.com/problems/sum-of-subarray-minimums/solutions/178876/stack-solution-with-very-detailed-explanation-step-by-step/)

<!-- Fill a double type array method -->
fill_n(&dp[0][0], 12, -1.3);


<!-- Input output Method -->
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

<!-- new syntax for 3d, 2d vec -->

vector dp(n + 1 , vector(n, vector<int>(n, 0)));

<!-- intialize all value with 99, it's a gnu function -->

int dp[1000] = {[0 ... 1000] = 99};

compile c++ file
g++ main.cpp -o main.exe

run it
.\main

for (auto r : v)
{
for (int x : r)
cout << x << " ";
cout << "\n";
}


for (int i = 0; i <= c.size(); i++)
{
    for (int j = 0; j <= t.size(); j++)
        cout << dp[i][j] << " ";
    cout << endl;
}