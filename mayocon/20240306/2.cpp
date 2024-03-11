// https://atcoder.jp/contests/abc343/tasks/abc343_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_kaibun(ll x) {
    string S;
    while (x > 0) {
        S.push_back(x % 10);
        x /= 10;
    }
    string T = S;
    reverse(S.begin(), S.end());
    return T == S;
}

void solve() {
    ll N;
    cin >> N;
    ll ans = -1;
    for (ll x = 1; x*x*x <= N; x++) {
        if (is_kaibun(x*x*x)) ans = x*x*x;
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
