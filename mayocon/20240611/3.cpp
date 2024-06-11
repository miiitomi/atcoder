// https://atcoder.jp/contests/abc183/tasks/abc183_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, W;
    cin >> N >> W;
    vector<ll> S((ll)(2e+5) + 10, 0);
    for (int i = 0; i < N; i++) {
        ll s, t, p;
        cin >> s >> t >> p;
        S[s] += p;
        S[t] -= p;
    }

    for (ll t = 0; t <= (ll)(2e+5) + 5; t++) {
        if (S[t] > W) {
            cout << "No\n";
            return;
        }
        S[t+1] += S[t];
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
