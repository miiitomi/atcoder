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
    vector<int> A(N);
    K = N - K;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    ll ans = INF;
    for (int i = 0; i+K-1 <= N-1; i++) {
        ans = min(ans, 0LL+A[i+K-1]-A[i]);
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
