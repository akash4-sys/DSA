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