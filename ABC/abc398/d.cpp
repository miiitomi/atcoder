#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, R, C;
    cin >> N >> R >> C;
    set<pair<ll,ll>> st;
    st.insert({0, 0});
    ll X = 0, Y = 0;

    while (N--) {
        char c;
        cin >> c;
        if (c == 'N') {
            X++;
            R++;
        } else if (c == 'S') {
            X--;
            R--;
        } else if (c == 'W') {
            Y++;
            C++;
        } else {
            Y--;
            C--;
        }
        st.insert({X, Y});
        if (st.contains({R, C})) cout << "1";
        else cout << "0";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
