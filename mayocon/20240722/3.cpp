// https://atcoder.jp/contests/abc266/tasks/abc266_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll cross_produxt(pair<ll,ll> p, pair<ll,ll> q) {
    return p.first*q.second - p.second*q.first;
}

void solve() {
    vector<ll> X(4), Y(4);
    for (int i = 0; i < 4; i++) cin >> X[i] >> Y[i];
    vector<bool> b(4);
    for (int i = 0; i < 4; i++) {
        ll tmp = cross_produxt({X[(i+1)%4] - X[i%4], Y[(i+1)%4] - Y[i%4]}, {X[(i-1+4)%4] - X[i%4], Y[(i-1+4)%4] - Y[i%4]});
        b[i] = (tmp >= 0);
    }
    if (b[0] == b[1] && b[1] == b[2] && b[2] == b[3]) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
