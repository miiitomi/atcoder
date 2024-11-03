#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    multiset<int> st;
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int x;
        cin >> x;
        if (st.contains(x)) {
            ans++;
            st.erase(st.find(x));
        } else {
            st.insert(x);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
