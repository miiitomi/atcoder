#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, Q;
    cin >> N >> Q;
    dsu U(N);
    vector<set<int>> S(N);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            u = U.leader(u);
            v = U.leader(v);
            if (u == v) continue;
            int r = U.merge(u, v);
            if (r == v) swap(u, v);
            if (S[v].size() > S[u].size()) swap(S[u], S[v]);
            for (int x: S[v]) S[u].insert(x);
        } else if (t == 2) {
            int v;
            cin >> v;
            v--;
            int r = U.leader(v);
            if (S[r].contains(v)) S[r].erase(v);
            else S[r].insert(v);
        } else {
            int v;
            cin >> v;
            v--;
            v = U.leader(v);
            if (S[v].empty()) cout << "No\n";
            else cout << "Yes\n";
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
