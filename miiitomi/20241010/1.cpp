// https://atcoder.jp/contests/abc154/tasks/abc154_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    set<int> st;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (st.contains(a)) {
            cout << "NO\n";
            return;
        }
        st.insert(a);
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
