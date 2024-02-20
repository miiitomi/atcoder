#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> pair<T, T> ext_gcd(T a, T b) {
    // a*x + b*y = gcd(a, b) となるような整数の組 (x, y) を返す.
    if (b == 0) return make_pair(1, 0);
    T x, y;
    tie(y, x) = ext_gcd(b, a % b);
    y -= a / b * x;
    return make_pair(x, y);
}
int main() {
    ll a = 3, b = 5;
    auto res = ext_gcd(a, b);
    cout << res.first << " " << res.second << "\n";
}
