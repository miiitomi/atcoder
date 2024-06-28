// https://atcoder.jp/contests/abc247/tasks/abc247_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    deque<pair<ll,ll>> D;
    ll Q;
    cin >> Q;
    while (Q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x, c;
            cin >> x >> c;
            D.push_back({x, c});
        } else {
            ll c;
            cin >> c;
            ll ans = 0;
            while (c > 0) {
                auto &p = D.front();
                if (c >= p.second) {
                    c -= p.second;
                    ans += p.first*p.second;
                    D.pop_front();
                } else {
                    ans += p.first*c;
                    p.second -= c;
                    c = 0;
                }
            }
            cout << ans << "\n";
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
