// https://atcoder.jp/contests/abc068/tasks/arc079_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll,ll>> st;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        st.insert({a, b});
    }
    for (int i = 2; i <= N-1; i++) {
        if (st.contains(make_pair(1, i)) && st.contains(make_pair(i, N))) {
            cout << "POSSIBLE\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
