// https://atcoder.jp/contests/abc241/tasks/abc241_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll Q;
    cin >> Q;
    multiset<ll> S;
    while (Q--) {
        ll t, x, k=0;
        cin >> t >> x;
        if (t == 1) {
            S.insert(x);
        } else if (t == 2) {
            cin >> k;
            auto iter = S.lower_bound(x+1);
            bool ok = true;
            while (k--) {
                if (iter == S.begin()) {
                    ok = false;
                    break;
                }
                iter--;
            }
            if (!ok) cout << "-1\n";
            else cout << *iter << "\n";
        } else {
            cin >> k;
            k--;
            auto iter = S.lower_bound(x);
            bool ok = (iter != S.end());
            while (ok && k--) {
                iter++;
                if (iter == S.end()) ok = false;
            }
            if (!ok) cout << "-1\n";
            else cout << *iter << "\n";
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
