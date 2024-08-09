// https://atcoder.jp/contests/abc259/tasks/abc259_e
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
    vector<ll> m(N);
    vector<vector<ll>> p(N), e(N);
    map<ll, pair<ll,ll>> mp;
    for (int i = 0; i < N; i++) {
        cin >> m[i];
        p[i].resize(m[i]); e[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++) {
            cin >> p[i][j] >> e[i][j];
            if (!mp.count(p[i][j])) {
                mp[p[i][j]] = {e[i][j], 0};
            } else if (e[i][j] > mp[p[i][j]].first) {
                mp[p[i][j]] = {e[i][j], mp[p[i][j]].first};
            } else if (e[i][j] > mp[p[i][j]].second) {
                mp[p[i][j]] = {mp[p[i][j]].first, e[i][j]};
            }
        }
    }
    set<vector<pair<ll,ll>>> S;
    for (int i = 0; i < N; i++) {
        vector<pair<ll,ll>> v;
        for (int j = 0; j < m[i]; j++) {
            auto [f, s] = mp[p[i][j]];
            if (f!=s && f == e[i][j]) {
                v.push_back({p[i][j], s});
            }
        }
        sort(v.begin(), v.end());
        S.insert(v);
    }

    cout << S.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
