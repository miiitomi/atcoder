// https://atcoder.jp/contests/abc147/tasks/abc147_c
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
    vector<ll> A(N);
    vector<vector<ll>> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        x[i].resize(A[i]);
        y[i].resize(A[i]);
        for (int j = 0; j < A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }

    ll ans = -1;
    for (ll s = 0; s < (1LL << N); s++) {
        ll cnt = 0;
        bool is_ok = true;
        for (int i = 0; i < N; i++) {
            if (!(s & (1 << i))) continue;
            cnt++;
            for (int j = 0; j < A[i]; j++) {
                if (!((y[i][j] && s&(1 << x[i][j])) || (!y[i][j] && !(s&(1 << x[i][j]))))) {
                    is_ok = false;
                    break;
                }
            }
            if (!is_ok) break;
        }
        if (is_ok) ans = max(ans, cnt);
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
