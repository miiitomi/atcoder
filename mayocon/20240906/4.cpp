// https://atcoder.jp/contests/abc309/tasks/abc309_e
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
    vector<ll> p(N, -1);
    for (int i = 1; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> q(N, 0);
    for (int i = 0; i < M; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y++;
        q[x] = max(q[x], y);
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (i >= 1) {
            q[i] = max(q[i], q[p[i]]-1);
        }
        if (q[i] >= 1) ans++;
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
