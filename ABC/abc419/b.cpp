#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int Q;
    cin >> Q;
    multiset<int> st;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            st.insert(x);
        } else {
            auto iter = st.begin();
            cout << *iter << "\n";
            st.erase(iter);
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
