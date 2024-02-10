#include <bits/stdc++.h>
#include <atcoder/math>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using namespace boost::multiprecision;
using ll = long long;

cpp_int mod(cpp_int a, cpp_int m) {
    return (a % m + m) % m;
}

// 拡張 Euclid の互除法
// ap + bq = gcd(a, b) となる (p, q) を求め、d = gcd(a, b) をリターンします
cpp_int extGcd(cpp_int a, cpp_int b, cpp_int &p, cpp_int &q) {  
    if (b == 0) { p = 1; q = 0; return a; }  
    cpp_int d = extGcd(b, a%b, q, p);  
    q -= a/b * p;  
    return d;  
}

// 中国剰余定理
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<cpp_int, cpp_int> ChineseRem(cpp_int b1, cpp_int m1, cpp_int b2, cpp_int m2) {
  cpp_int p, q;
  cpp_int d = extGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  cpp_int m = m1 * (m2/d); // lcm of (m1, m2)
  cpp_int tmp = (b2 - b1) / d * p % (m2/d);
  cpp_int r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}

pair<cpp_int, cpp_int> f(ll x, ll y) {
    if (x == 0) {
        if (y == 1) return make_pair(2, 0);
        else if (y == 2) return make_pair(1, 0);
        else return make_pair(0, 0);
    }
    if (y == 1) {
        return make_pair(2, 0);
    }
    vector<ll> r = {0, 2}, m = {x, y};
    pair<cpp_int, cpp_int> p = ChineseRem(0, x, 2, y);
    if (p.first > 0 || p.second > 0) {
        cpp_int a = p.first / x;
        cpp_int b = (p.first - 2) / y;
        if (abs(a) <= (ll)1e+18 && abs(b) <= (ll)1e+18) return make_pair(a, b);
    }
    p = ChineseRem(0, x, y-2, y);
    if (p.first > 0 || p.second > 0) {
        cpp_int a = p.first / x;
        cpp_int b = (p.first - 2) / y;
        if (abs(a) <= (ll)1e+18 && abs(b) <= (ll)1e+18) return make_pair(a, b);
    }

    return make_pair(-1, -1);
}

void solve() {
    ll x, y;
    cin >> x >> y;
    pair<cpp_int, cpp_int> res  = f(min(abs(x), abs(y)), max(abs(x), abs(y)));
    // cout << res.first << " " << res.second << endl;
    if (res.first > 0 || res.second > 0) {
        cpp_int b1 = res.first, b2 = res.second;
        if (abs(x*b1 - y*b2) == 2) cout << b2 << " " << b1 << endl;
        else if (abs(x*(-b1) - y*b2) == 2) cout << b2 << " " << -b1 << endl;
        else if (abs(x*(b1) - y*(-b2)) == 2) cout << -b2 << " " << b1 << endl;
        else if (abs(x*(-b1) - y*(-b2)) == 2) cout << -b2 << " " << -b1 << endl;
        else if (abs(x*b2 - y*b1) == 2) cout << b1 << " " << b2 << endl;
        else if (abs(x*(-b2) - y*b1) == 2) cout << b1 << " " << -b2 << endl;
        else if (abs(x*(b2) - y*(-b1)) == 2) cout << -b1 << " " << b2 << endl;
        else if (abs(x*(-b2) - y*(-b1)) == 2) cout << -b1 << " " << -b2 << endl;
    } else {
        cout << -1 << endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
