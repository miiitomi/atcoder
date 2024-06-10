// https://atcoder.jp/contests/abc319/tasks/abc319_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll R = 840;

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> P(N-1), T(N-1);
    for (int i = 0; i < N-1; i++) cin >> P[i] >> T[i];

    vector<ll> tmp(R, 0);
    for (ll s = 0; s < R; s++) {
        ll t = s;
        t += X;
        for (int i = 0; i < N-1; i++) {
            if (t % P[i] != 0) t += P[i] - (t % P[i]);
            t += T[i];
        }
        t += Y;
        tmp[s] = t-s;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        ll q;
        cin >> q;
        cout << q + tmp[q % R] << "\n";
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
