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
    ll tmp = 0;
    priority_queue<ll> PQ;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            PQ.push(-tmp);
        } else if (k == 2) {
            ll t;
            cin >> t;
            tmp += t;
        } else {
            ll h;
            cin >> h;
            ll ans = 0;
            while (!PQ.empty() && PQ.top()+tmp >= h) {
                ans++;
                PQ.pop();
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
