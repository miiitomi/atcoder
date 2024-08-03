// https://atcoder.jp/contests/abc313/tasks/abc313_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    ll x = 0;
    for (int i = 1; i < N; i++) {
        x = max(x, P[i]+1-P[0]);
    }
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
