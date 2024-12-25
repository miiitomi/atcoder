// https://atcoder.jp/contests/abc304/tasks/abc304_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    dsu UF(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        UF.merge(u, v);
    }
    int K;
    cin >> K;
    set<pair<int,int>> st;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        x = UF.leader(x);
        y = UF.leader(y);
        st.insert({x,y});
        st.insert({y,x});
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        p = UF.leader(p);
        q = UF.leader(q);
        if (st.contains({p,q})) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
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
