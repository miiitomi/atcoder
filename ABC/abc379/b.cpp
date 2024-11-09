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
    string S;
    cin >> S;
    int tmp = 0;
    priority_queue<ll> Q;
    for (char c : S) {
        if (c == 'O') tmp++;
        else {
            Q.push(tmp);
            tmp = 0;
        }
    }
    Q.push(tmp);
    ll ans = 0;
    while (!Q.empty()) {
        ll x = Q.top();
        Q.pop();
        if (x >= K) {
            ans++;
            Q.push(x - K);
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
