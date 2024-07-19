// https://atcoder.jp/contests/abc178/tasks/abc178_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> T mod_pow(T a, ll n) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    return res * res;
}

void solve() {
    ll N;
    cin >> N;
    mint ans = 0;
    ans += mod_pow((mint)10, N);
    ans -= mod_pow((mint)9, N);
    ans -= mod_pow((mint)9, N);
    ans += mod_pow((mint)8, N);
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
