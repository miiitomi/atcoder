// https://atcoder.jp/contests/abc271/tasks/abc271_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];
    vector<map<ll,ll>> mp(N);
    for (ll s = 0; s < (1 << (N-1)); s++) {
        ll a = A[0][0];
        ll x = 0, y = 0;
        for (int i = 0; i < (N-1); i++) {
            if (s & (1 << i)) x++;
            else y++;
            a ^= A[x][y];
        }
        mp[x][a]++;
    }
    ll ans = 0;
    for (ll t = 0; t < (1 << (N-1)); t++) {
        ll a = 0;
        ll x = N-1, y = N-1;
        for (int i = 0; i < (N-1); i++) {
            a ^= A[x][y];
            if (t & (1 << i)) x--;
            else y--;
        }
        ans += mp[x][a];
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
