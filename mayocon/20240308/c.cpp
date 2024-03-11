// https://atcoder.jp/contests/abc338/tasks/abc338_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<ll> Q(N), A(N), B(N);
    for (int i = 0; i < N; i++) cin >> Q[i];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < N; j++) cin >> B[j];

    ll ans = -1;

    for (ll a = 0; a <= 1e+6; a++) {
        bool ok = true;
        ll b = 1e+9;
        for (int i = 0; i < N; i++) {
            ll s = Q[i] - a * A[i];
            if (s < 0) ok = false;
            else {
                if (B[i] > 0) b = min(b, s / B[i]);
            }
        }
        if (ok) ans = max(ans, a+b);
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
