// https://atcoder.jp/contests/abc241/tasks/abc241_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, N;
    cin >> H >> W >> N;
    pair<ll,ll> s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    s.first--; s.second--; g.first--; g.second--;
    map<ll, vector<ll>> R, C;
    for (ll i = 0; i < N; i++) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        R[r].push_back(c);
        C[c].push_back(r);
    }
    for (auto iter = R.begin(); iter != R.end(); iter++) sort(iter->second.begin(), iter->second.end());
    for (auto iter = C.begin(); iter != C.end(); iter++) sort(iter->second.begin(), iter->second.end());

    map<pair<ll,ll>, ll> d;
    d[s] = 0;
    queue<pair<ll,ll>> Q;
    Q.push(s);
    while (!Q.empty()) {
        pair<ll,ll> p = Q.front();

        if (p == g) {
            cout << d[p] << endl;
            return;
        }

        auto [r, c] = p;
        Q.pop();

        auto iter1 = lower_bound(R[r].begin(), R[r].end(), c);
        if (iter1 != R[r].end()) {
            ll c1 = *iter1 - 1;
            if (!d.contains({r, c1})) {
                d[{r, c1}] = d[p] + 1;
                Q.push({r, c1});
            }
        }
        if (iter1 != R[r].begin()) {
            iter1--;
            ll c1 = *iter1 + 1;
            if (!d.contains({r, c1})) {
                d[{r, c1}] = d[p] + 1;
                Q.push({r, c1});
            }
        }

        auto iter2 = lower_bound(C[c].begin(), C[c].end(), r);
        if (iter2 != C[c].end()) {
            ll r1 = *iter2 - 1;
            if (!d.contains({r1, c})) {
                d[{r1, c}] = d[p] + 1;
                Q.push({r1, c});
            }
        }
        if (iter2 != C[c].begin()) {
            iter2--;
            ll r1 = *iter2 + 1;
            if (!d.contains({r1, c})) {
                d[{r1, c}] = d[p] + 1;
                Q.push({r1, c});
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
