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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll>> p(40, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) p[0][i] = A[i];
    for (int k = 1; k < 40; k++) {
        for (int i = 0; i < N; i++) {
            p[k][i] = p[k-1][i] + p[k-1][(i + p[k-1][i]) % N];
        }
    }
    ll ans = 0;
    for (ll k = 0; k < 40; k++) {
        if (K & (1LL << k)) {
            ans += p[k][ans%N];
        }
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
