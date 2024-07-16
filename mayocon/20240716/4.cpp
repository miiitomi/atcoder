// https://atcoder.jp/contests/abc217/tasks/abc217_e
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
    multiset<ll> S;
    queue<ll> T;
    while (Q--) {
        ll k;
        cin >> k;
        if (k == 1) {
            ll x;
            cin >> x;
            T.push(x);
        } else if (k == 3) {
            while (!T.empty()) {
                S.insert(T.front());
                T.pop();
            }
        } else {
            if (!S.empty()) {
                ll x = *S.begin();
                S.erase(S.begin());
                cout << x << "\n";
            } else {
                ll x = T.front();
                T.pop();
                cout << x << "\n";
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
