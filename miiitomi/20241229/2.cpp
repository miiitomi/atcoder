// https://atcoder.jp/contests/abc185/tasks/abc185_d
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
    vector<ll> A(M+2);
    for (int i = 0; i < M; i++) cin >> A[i];
    A[M] = 0;
    A[M+1] = N+1;
    sort(A.begin(), A.end());
    vector<ll> B;
    for (int i = 0; i <= M; i++) {
        if (A[i+1]-A[i] >= 2) {
            B.push_back(A[i+1]-A[i]-1);
        }
    }
    sort(B.begin(), B.end());
    ll g = B[0];
    ll ans = 0;
    for (ll b : B) ans += (b + g-1)/g;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
