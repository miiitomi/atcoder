// https://atcoder.jp/contests/abc250/tasks/abc250_g
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
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll ans = 0;
    while (N--) {
        ll p;
        cin >> p;
        pq.push(p);
        if (pq.top() < p) {
            ll q = pq.top();
            pq.pop();
            ans += p - q;
            pq.push(p);
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
