// https://atcoder.jp/contests/abc217/tasks/abc217_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll L, Q;
    cin >> L >> Q;
    set<ll> S;
    S.insert(0);
    S.insert(L);
    while (Q--) {
        ll c, x;
        cin >> c >> x;
        if (c == 1) {
            S.insert(x);
        } else {
            auto iter = S.lower_bound(x);
            ll tmp = *iter;
            iter--;
            tmp -= *iter;
            cout << tmp << "\n";
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
