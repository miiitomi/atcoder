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
    vector<vector<ll>> p(41, vector<ll>(N)), q(41, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) cin >> q[0][i];
    for (int i = 0; i < N; i++) {
        cin >> p[0][i];
        p[0][i]--;
    }
    for (int j = 1; j <= 40; j++) {
        for (int i = 0; i < N; i++) {
            p[j][i] = p[j-1][p[j-1][i]];
            q[j][i] = q[j-1][p[j-1][i]] + q[j-1][i];
        }
    }

    vector<bool> cnt(N, false);
    for (int i = 0; i < N; i++) {
        ll x = i, sum = 0;
        for (ll k = 40; k >= 0; k--) {
            if (sum + q[k][x] < M) {
                sum += q[k][x];
                x = p[k][x];
            }
        }
        cnt[x] = true;
    }
    for (int i = 0; i < N; i++) if (cnt[i]) cout << i+1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
