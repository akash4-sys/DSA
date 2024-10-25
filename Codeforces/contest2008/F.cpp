#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int P = 1000000007;

template<typename T>
constexpr T power(T a, ll b) {
    T res {1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

template<int P>
constexpr int mulMod(int a, int b) {
    return 1ULL * a * b % P;
}

template<ll P>
constexpr ll mulMod(ll a, ll b) {
    ll res = a * b - ll(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template<typename U, U P>
requires std::integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x {0} {}
    
    template<typename T>
    requires std::integral<T>
    constexpr ModIntBase(T x_) : x {norm(x_ % T {P})} {}
    
    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    
    constexpr U val() const {
        return x;
    }
    
    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }
    
    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }
    
    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }
    
    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    
    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    
    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }
    
    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }
    
    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }
    
    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }
    
    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }
    
private:
    U x;
};

template<int P>
using ModInt = ModIntBase<int, P>;

template<ll P>
using ModInt64 = ModIntBase<ll, P>;
using MInt = ModInt<P>;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << "\n"

MInt solve()
{
    int n = II;
    MInt N = n, sum = 0, total = 0;
    MInt pairs = (N * (N - 1)) / 2;
    vector<MInt> v(n);
    for (int i = 0; i < n; i++)
        v[i] = II;
    for (int i = n - 1; i >= 0; i--)
        total += v[i];
    for (int i = 0; i < n; i++)
        total -= v[i], sum += (total * v[i]);
    return sum / pairs;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << endl;
    return 0;
}