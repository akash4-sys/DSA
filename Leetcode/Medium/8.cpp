#include "../../headers.h"

class Solution
{
public:
    int myAtoi(string s)
    {
        long long num=0;
        int sign=0,c2=0;
        for(int i=0;i<s.size();i++){
            if((c2==1 || sign!=0) && !isdigit(s[i])) break;
            if(isspace(s[i])) continue;
            if(s[i]=='+') sign=1;
            else if(s[i]=='-') sign=2;
            else if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
                if(sign==2 && -num<=INT_MIN) return INT_MIN;
                else if((sign==0 || sign==1) && num>=INT_MAX) return INT_MAX;
                c2=1;
            }else break;
        }
        return sign==2 ? -num : num;
    }
};