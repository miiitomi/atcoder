// https://atcoder.jp/contests/abc061/tasks/abc061_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    ll left = 0, right = 1e+5 + 1;
    while (right - left > 1) {
        ll m = (left + right)/2;
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] <= m) cnt += b[i];
        }
        if (cnt < K) left = m;
        else right = m;
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
