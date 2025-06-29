#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, C;
    cin >> N >> C;
    C--;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    A[C]++;
    vector<ll> v(N, 0);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int l, int r) {
        return A[l] > A[r];
    });
    auto B = A;
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    for (int i = 0; i < N-1; i++) B[i+1] += B[i];
    vector<mint> x(N, 0);
    mint y = 0;
    for (int i = 0; i < N; i++) {
        int a = v[i];
        x[a] = (B.back() - 1 + y) * (((mint)B[i] - 1).inv());
        y += A[a] * x[a];
    }
    cout << x[C].val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
