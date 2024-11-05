// https://atcoder.jp/contests/abc128/tasks/abc128_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, K;
    cin >> N >> K;
    deque<ll> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];
    ll ans = 0;
    for (int k = 1; k <= min(K, N); k++) {
        for (int l = 0; l <= k; l++) {
            deque<ll> W = V;
            int r = k-l;
            ll tmp = 0;
            priority_queue<ll, vector<ll>, greater<ll>> Q;
            for (int i = 0; i < l; i++) {
                ll x = W.front();
                W.pop_front();
                tmp += x;
                Q.push(x);
            }
            for (int i = 0; i < r; i++) {
                ll x = W.back();
                W.pop_back();
                tmp += x;
                Q.push(x);
            }
            for (int i = 0; i < K-k && !Q.empty() && Q.top() < 0; i++) {
                ll x = Q.top();
                Q.pop();
                tmp -= x;
            }
            ans = max(ans, tmp);
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
