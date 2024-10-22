// https://atcoder.jp/contests/abc050/tasks/arc066_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 1e+9 + 7;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> B;
    ll ans = 1;
    if (N % 2 == 0) {
        for (ll x = 1; x <= N-1; x += 2) {
            B.push_back(x);
            B.push_back(x);
            ans = (ans * 2) % MOD;
        }
    } else {
        B.push_back(0);
        for (ll x = 2; x <= N-1; x += 2) {
            B.push_back(x);
            B.push_back(x);
            ans = (ans * 2) % MOD;
        }
    }
    if (A == B) cout << ans << endl;
    else cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
