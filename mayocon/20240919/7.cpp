// https://atcoder.jp/contests/abc247/tasks/abc247_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 1e+9;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> C(150, vector<ll>(150, -1));
    for (int i = 0; i < N; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        C[a][b] = max(C[a][b], c);
    }
    mcf_graph<ll,ll> G(302);
    ll s = 300, t = 301;
    for (int i = 0; i < 150; i++) {
        G.add_edge(s, i, 1, 0);
        G.add_edge(150+i, t, 1, 0);
    }
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            if (C[i][j] == -1) continue;
            G.add_edge(i, 150+j, 1, INF-C[i][j]);
        }
    }
    vector<pair<ll,ll>> res = G.slope(s, t);
    vector<ll> ans(res.back().first+1, 0);
    for (int i = 0; i < (int)res.size()-1; i++) {
        for (ll k = res[i].first+1; k <= res[i+1].first; k++) {
            ans[k] = res[i].second + (res[i+1].second-res[i].second)*(k-res[i].first)/(res[i+1].first-res[i].first);
            ans[k] = k*INF - ans[k];
        }
    }
    cout << ans.size()-1 << endl;
    for (ll i = 1; i < (int)ans.size(); i++) cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
