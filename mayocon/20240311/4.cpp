// https://atcoder.jp/contests/abc080/tasks/abc080_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<vector<bool>> is_open(N,vector<bool>(10, false));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 10; k++) {
            int s;
            cin >> s;
            if (s) is_open[i][k] = true;
        }
    }
    vector<vector<ll>> P(N, vector<ll>(11));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= 10; k++) cin >> P[i][k];
    }

    ll ans = -1e+18;
    for (ll s = 1; s < (1 << 10); s++) {
        vector<int> cnt(N, 0);
        for (int d = 0; d < 10; d++) {
            if (!(s & (1 << d))) continue;
            for (int i = 0; i < N; i++) if (is_open[i][d]) cnt[i]++;
        }
        ll tmp = 0;
        for (int i = 0; i < N; i++) tmp += P[i][cnt[i]];
        ans = max(ans, tmp);
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
