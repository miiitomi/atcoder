// https://atcoder.jp/contests/abc127/tasks/abc127_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    map<ll, ll> mp;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        mp[a]++;
    }

    for (int i = 0; i < M; i++) {
        ll b, c;
        cin >> b >> c;
        while (b > 0 && mp.begin()->first < c) {
            ll a = mp.begin()->first;
            ll x = min(b, mp[a]);
            mp[c] += x;
            b -= x;
            mp[a] -= x;
            if (mp[a] == 0) mp.erase(a);
        }
    }

    ll ans = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) ans += iter->first * iter->second;
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
