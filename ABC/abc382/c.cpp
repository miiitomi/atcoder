#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i] = a;
        if (i > 0) A[i] = min(A[i], A[i-1]);
    }
    while (M--) {
        ll b;
        cin >> b;
        ll left = -1, right = N;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            if (b >= A[m]) right = m;
            else left = m;
        }
        if (right == N) cout << -1 << "\n";
        else cout << right + 1 << "\n";
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
