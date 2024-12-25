// https://atcoder.jp/contests/abc107/tasks/arc101_a
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
    vector<ll> M, P;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        if (x < 0) M.push_back(-x);
        else if (x > 0) P.push_back(x);
        else K--;
    }
    if (K == 0) {
        cout << 0 << endl;
        return;
    }
    sort(M.begin(), M.end());
    ll ans = INF;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < (int)M.size(); i++) {
            if (K-1-i <= 0) {
                ans = min(ans, M[i]);
                continue;
            }
            ll tmp = 2*M[i];
            ll r = K - 1 - i;
            r--;
            if (r < P.size()) {
                tmp += P[r];
                ans = min(ans, tmp);
            }
        }
        swap(M, P);
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
