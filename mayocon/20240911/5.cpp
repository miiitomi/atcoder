// https://atcoder.jp/contests/abc325/tasks/abc325_d
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

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    for (int i = 0; i < N; i++) {
        pair<ll,ll> p;
        cin >> p.first >> p.second;
        Q.push(p);
    }
    priority_queue<ll, vector<ll>, greater<ll>> R;
    ll tmp = 0;
    ll ans = 0;

    while (!Q.empty()) {
        while (tmp < Q.top().first && !R.empty()) {
            if (R.top() >= tmp) {
                ans++;
                tmp++;
                R.pop();
            } else {
                R.pop();
            }
        }
        tmp = Q.top().first;
        while (!Q.empty() && tmp == Q.top().first) {
            R.push(Q.top().first + Q.top().second);
            Q.pop();
        }
    }
    while (!R.empty()) {
        if (tmp > R.top()) R.pop();
        else {
            tmp++;
            ans++;
            R.pop();
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
