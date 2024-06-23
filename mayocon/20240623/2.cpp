// https://atcoder.jp/contests/abc343/tasks/abc343_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_kaibun(ll X) {
    string S;
    while (X > 0) {
        S.push_back(X%10 + '0');
        X /= 10;
    }
    string T = S;
    reverse(T.begin(), T.end());
    return S == T;
}

void solve() {
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll x = 1; x*x*x <= N; x++) {
        ll K = x*x*x;
        if (is_kaibun(K)) ans = max(ans, K);
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
