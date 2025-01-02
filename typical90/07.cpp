// https://atcoder.jp/contests/typical90/tasks/typical90_g
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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    ll Q;
    cin >> Q;
    while (Q--) {
        ll b;
        cin >> b;
        ll ans = INF;
        auto iter = lower_bound(A.begin(), A.end(), b);
        if (iter != A.end()) ans = min(ans, abs(*iter - b));
        if (iter != A.begin()) {
            iter--;
            ans = min(ans, abs(*iter - b));
        }
        cout << ans << "\n";
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
