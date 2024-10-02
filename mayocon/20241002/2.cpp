// https://atcoder.jp/contests/abc343/tasks/abc343_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool is_kaibun(ll N) {
    string S;
    while (N > 0) {
        S.push_back('0'+(N%10));
        N /= 10;
    }
    string T = S;
    reverse(T.begin(), T.end());
    return S == T;
}

void solve() {
    ll N;
    cin >> N;
    ll ans = -1;
    for (ll x = 1; x*x*x <= N; x++) {
        ll K = x*x*x;
        if (is_kaibun(K)) ans = K;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
