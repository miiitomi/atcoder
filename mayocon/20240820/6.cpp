// https://atcoder.jp/contests/abc215/tasks/abc215_f
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
    vector<pair<ll,ll>> p(N);
    for (int i = 0; i < N; i++) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    ll left = -1, right = 2e+9;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        bool tmp = false;
        queue<pair<ll,ll>> Q;
        ll mi = INF, ma = -INF;
        for (auto &q : p) {
            while (!Q.empty() && Q.front().first < q.first - m) {
                mi = min(mi, Q.front().second);
                ma = max(ma, Q.front().second);
                Q.pop();
            }
            if (mi < q.second - m || q.second + m < ma) {
                tmp = true;
                break;
            }
            Q.push(q);
        }
        if (tmp) left = m;
        else right = m;
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
