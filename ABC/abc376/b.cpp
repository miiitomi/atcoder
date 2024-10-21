#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    ll left = 0, right = 1, cnt = 0;
    while (Q--) {
        char c;
        ll t;
        cin >> c >> t;
        t--;
        ll ans = INF;
        if (c == 'L') {
            for (ll tmp = left; tmp != right; tmp = (tmp-1+N)%N) {
                if (tmp == t) ans = min(ans, (left - tmp + N) % N);
            }
            for (ll tmp = left; tmp != right; tmp = (tmp+1)%N) {
                if (tmp == t) ans = min(ans, (tmp - left + N) % N);
            }
            left = t;
        } else {
            for (ll tmp = right; tmp != left; tmp = (tmp-1+N)%N) {
                if (tmp == t) ans = min(ans, (right - tmp + N) % N);
            }
            for (ll tmp = right; tmp != left; tmp = (tmp+1)%N) {
                if (tmp == t) ans = min(ans, (tmp - right + N) % N);
            }
            right = t;
        }
        cnt += ans;
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
