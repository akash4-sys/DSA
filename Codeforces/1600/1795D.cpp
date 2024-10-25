#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int P = 998244353;

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

struct Comb {
    int n;
    std::vector<MInt> _fac;
    std::vector<MInt> _invfac;
    std::vector<MInt> _inv;
    
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    MInt fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    MInt invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    MInt inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    MInt nCr(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

int main()
{
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto &wt : w)
        cin >> wt;
    
    MInt res = comb.nCr(n / 3, n / 6);
    for (int i = 0; i < n; i += 3)
    {
        MInt x = min({w[i], w[i + 1], w[i + 2]}), cnt = 0;
        for (int j = i; j < i + 3; j++)
            if (w[j] == x)
                cnt += 1;
        res *= cnt;
    }
    cout << res;
    return 0;
}