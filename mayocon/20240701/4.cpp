// https://atcoder.jp/contests/abc349/tasks/abc349_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll L, R;
    cin >> L >> R;
    vector<pair<ll,ll>> ans;
    while (L < R) {
        ll i = 0;
        for (ll k = 1; k< 64; k++) {
            if (L % (1LL << k) != 0 || (L + (1LL << k) > R)) break;
            i++;
        }
        ans.push_back({L, L+(1LL << i)});
        L += (1LL << i);
    }
    cout << ans.size() << "\n";
    for (auto p : ans) cout << p.first << " " << p.second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
