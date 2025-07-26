#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    sort(X.begin(), X.end());
    ll ans = X.back() - X.front();
    vector<ll> Y(N-1);
    for (int i = 0; i < N-1; i++) Y[i] = X[i+1] - X[i];
    sort(Y.begin(), Y.end());
    reverse(Y.begin(), Y.end());
    for (int i = 0; i < M-1; i++) ans -= Y[i];
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
