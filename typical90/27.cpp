// https://atcoder.jp/contests/typical90/tasks/typical90_aa
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    set<string> st;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        if (st.contains(s)) continue;
        st.insert(s);
        cout << i << "\n";
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
