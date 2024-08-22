// https://atcoder.jp/contests/abc239/tasks/abc239_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<ll> dx{1, 2, 2, 1, -1, -2, -2, -1}, dy{2, 1, -1, -2, -2, -1, 1, 2};

void solve() {
    pair<ll,ll> p, q;
    cin >> p.first >> p.second >> q.first >> q.second;
    vector<pair<ll,ll>> P;
    for (int k = 0; k < 8; k++) P.push_back({p.first+dx[k], p.second+dy[k]});
    for (int k = 0; k < 8; k++) {
        if (find(P.begin(), P.end(), make_pair(q.first+dx[k], q.second+dy[k])) != P.end()) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
