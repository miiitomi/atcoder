// https://atcoder.jp/contests/abc318/tasks/abc318_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, D, P;
    cin >> N >> D >> P;
    vector<ll> F(N);
    for (int i = 0; i < N; i++) cin >> F[i];
    sort(F.begin(), F.end());
    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) S[i+1] = S[i] + F[i];

    ll ans = 1e+18;
    for (ll k = 0; k <= N; k++) {
        ll tmp = k*P;
        ll d = k*D;
        if (d < N) {
            tmp += S[N-d];
            ans = min(ans, tmp);
        } else {
            ans = min(ans, tmp);
            break;
        }
    }
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
