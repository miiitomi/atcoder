// https://atcoder.jp/contests/abc183/tasks/abc183_c
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
    vector<vector<ll>> T(N, vector<ll>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> T[i][j];
    vector<ll> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    ll ans = 0;
    do {
        if (v[0] != 0) continue;
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            tmp += T[v[i]][v[(i+1)%N]];
        }
        if (tmp == K) ans++;
    } while (next_permutation(v.begin(), v.end()));

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
