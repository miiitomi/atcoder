// https://atcoder.jp/contests/abc212/tasks/abc212_d
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
    multiset<ll> st;
    while (Q--) {
        int p;
        cin >> p;
        if (p == 1) {
            ll x;
            cin >> x;
            st.insert(x-tmp);
        } else if (p == 2) {
            ll x;
            cin >> x;
            tmp += x;
        } else {
            auto iter = st.begin();
            ll x = *iter + tmp;
            st.erase(iter);
            cout << x << "\n";
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
