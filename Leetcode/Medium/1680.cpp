#include "../../headers.h"

// More concise way
class Solution
{
public:
    int concatenatedBinary(int n)
    {
        int mod = 1e9 + 7;
        long ans = 0;
        for(long i = 1, shift = 0; i <= n; i++)
        {
            shift += !(i & (i - 1));
            ans = ((ans << shift) | i) % mod;
        }
        return ans;
    }
};

// Time complexity - O(N)
// Space complexity - O(1)

// In any number of power 2 there is only one set bit

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        int mod = 1e9 + 7;
        long ans = 0;
        for(long i = 1, shift = 0; i <= n; i++)
        {
            // here we are removing rightmost set bit and checking if it's all zero now
            // if it is then we add one to shift variable
            shift += (i & (i - 1)) == 0;
            ans <<= shift;
            ans += i;
            ans %= mod;
        }
        return ans;
    }
};

// Not working for integers above 20
class Solution
{
public:
    int concatenatedBinary(int n)
    {
        string binary;
        for (int i = 1; i <= n; i++)
        {
            string bin = bitset<8>(i).to_string();
            bin.erase(0, bin.find_first_not_of('0'));
            binary += bin;
        }

        int mod = 1e9 + 7;
        long long ans = 0, base = 1;
        for (int i = binary.size() - 1; i >= 0; i--)
        {
            if (binary[i] == '1')
                ans = (ans + base) % mod;
            base = (base * 2) % mod;
        }
        return ans;
    }
};