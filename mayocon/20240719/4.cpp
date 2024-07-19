// https://atcoder.jp/contests/abc156/tasks/abc156_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

mint C(int n, int r) {
    if (r > n || r < 0) return 0;
    if (r > n/2) r = n-r;
    mint a = 1, b = 1;
    for (int k = 0; k < r; k++) {
        a *= (n-k);
        b *= (k+1);
    }
    return a/b;
}

template<typename T> T mod_pow(T a, ll n) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    return res * res;
}

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    mint ans = mod_pow((mint)2, N) - 1;
    ans -= C(N, A);
    ans -= C(N, B);
    cout << ans.val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
