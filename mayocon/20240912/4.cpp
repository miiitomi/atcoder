// https://atcoder.jp/contests/abc112/tasks/abc112_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, s, t, u;
    cin >> N;
    vector<ll> x(N), y(N), h(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] != 0) {
            s = x[i]; t = y[i]; u = h[i];
        }
    }

    for (ll cx = 0; cx <= 100; cx++) {
        for (ll cy = 0; cy <= 100; cy++) {
            ll H = u + abs(s - cx) + abs(t - cy);
            bool is_ok = true;
            for (int i = 0; i < N; i++) {
                if (h[i] != max(0LL, H-abs(cx-x[i])-abs(cy-y[i]))) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) {
                cout << cx << " " << cy << " " << H << "\n";
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
