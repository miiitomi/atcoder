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
    map<ll, pair<ll,ll>> mp;
    vector<ll> m(N);
    vector<vector<ll>> p(N), e(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
        for (int j = 0; j < m[i]; j++) {
            ll P, E;
            cin >> P >> E;
            if (mp.contains(P)) {
                auto q = mp[P];
                if (E > q.first) {
                    q = {E, q.first};
                } else if (E > q.second) {
                    q = {q.first, E};
                }
                mp[P] = q;
            } else {
                mp[P] = make_pair(E, 0);
            }
            p[i].push_back(P);
            e[i].push_back(E);
        }
    }
    vector<vector<pair<ll,ll>>> V;
    for (int i = 0; i < N; i++) {
        vector<pair<ll,ll>> v;
        for (int j = 0; j < m[i]; j++) {
            auto q = mp[p[i][j]];
            if (q.first != e[i][j] || q.first == q.second) continue;
            v.push_back(make_pair(p[i][j], q.second));
        }
        sort(v.begin(), v.end());
        V.emplace_back(v);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    cout << V.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
