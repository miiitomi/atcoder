// https://atcoder.jp/contests/abc309/tasks/abc309_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    ll cnt = 0, tmp = 1;
    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        cnt += b;
        Q.push({a+1, b});
    }
    while (cnt > K) {
        auto [x, y] = Q.top();
        Q.pop();
        tmp = x;
        cnt -= y;
    }

    cout << tmp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
