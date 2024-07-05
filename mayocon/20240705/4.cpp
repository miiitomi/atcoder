// https://atcoder.jp/contests/abc344/tasks/abc344_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    map<ll, pair<ll, ll>> mp;
    mp[0] = {-1, INF};
    mp[INF] = {0, -1};
    ll b= 0;
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        mp[b].second = a;
        mp[a] = {b, INF};
        mp[INF].first = a;
        b = a;
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll k;
        cin >> k;
        if (k == 1) {
            ll x, y;
            cin >> x >> y;
            ll z = mp[x].second;
            mp[x].second = y;
            mp[y] = {x, z};
            mp[z].first = y;
        } else {
            ll x;
            cin >> x;
            auto [a, b] = mp[x];
            mp[a].second = b;
            mp[b].first = a;
        }
    }

    ll x = 0;
    while (x != INF) {
        if (x >= 1) {
            cout << x << " ";
        }
        x = mp[x].second;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
