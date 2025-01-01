// https://atcoder.jp/contests/abc291/tasks/abc291_b
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
    vector<ll> X(5*N);
    for (int i = 0; i < 5*N; i++) cin >> X[i];
    sort(X.begin(), X.end());
    double ans = 0;
    for (int i = 0; i < 3*N; i++) ans += X[N+i];
    ans /= 3*N;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
