// https://atcoder.jp/contests/typical90/tasks/typical90_aj
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N), Y(N), A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        A[i] = X[i]+Y[i];
        B[i] = X[i]-Y[i];
    }
    ll mia = *min_element(A.begin(), A.end());
    ll maa = *max_element(A.begin(), A.end());
    ll mib = *min_element(B.begin(), B.end());
    ll mab = *max_element(B.begin(), B.end());
    while (Q--) {
        ll q;
        cin >> q;
        q--;
        ll ans = -1;
        ans = max(ans, A[q]-mia);
        ans = max(ans, maa-A[q]);
        ans = max(ans, B[q]-mib);
        ans = max(ans, mab-B[q]);
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
