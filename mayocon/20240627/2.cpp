// https://atcoder.jp/contests/abc235/tasks/abc235_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    map<ll, vector<ll>> mp;
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        mp[a].push_back(i);
    }

    while (Q--) {
        ll x, k;
        cin >> x >> k;
        if (mp[x].empty()) {
            cout << -1 << endl;
        } else {
            vector<ll> &v = mp[x];
            if (v.size() < k) {
                cout << -1 << endl;
            } else {
                cout << v[k-1] << endl;
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
