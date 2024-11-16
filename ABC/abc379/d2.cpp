#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll Q;
    cin >> Q;
    vector<ll> A(Q, 0);
    queue<ll> B;
    for (int q = 0; q < Q; q++) {
        ll k;
        cin >> k;
        if (q > 0) A[q] = A[q-1];
        if (k == 2) {
            ll t;
            cin >> t;
            A[q] += t;
        } else if (k == 1) {
            B.push(q);
        } else {
            ll h;
            cin >> h;
            ll ans = 0;
            while (!B.empty() && A[q] - A[B.front()] >= h) {
                ans++;
                B.pop();
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
