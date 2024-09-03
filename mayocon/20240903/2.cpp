// https://atcoder.jp/contests/abc358/tasks/abc358_c
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
    vector<ll> S(N, 0);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'o') S[i] |= (1 << j);
        }
    }
    ll ans = INF;
    for (int s = 0; s < (1 << N); s++) {
        ll tmp = 0, t = 0;
        for (int i = 0; i < N; i++) {
            if (s & (1 << i)) {
                tmp++;
                t |= S[i];
            }
        }
        if (t == (1 << M)-1) ans = min(ans, tmp);
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
