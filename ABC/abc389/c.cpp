#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll Q;
    cin >> Q;
    deque<pair<ll,ll>> D;
    while (Q--) {
        ll k;
        cin >> k;
        if (k == 1) {
            ll l;
            cin >> l;
            ll s = 0;
            if (!D.empty()) {
                s = D.back().first + D.back().second;
            }
            D.push_back({s, l});
        } else if (k == 2) {
            D.pop_front();
        } else {
            ll a;
            cin >> a;
            a--;
            ll s = D.front().first;
            cout << D[a].first-s << "\n";
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
