// https://atcoder.jp/contests/abc352/tasks/abc352_g
#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<vector<mint>> v;
vector<mint> rec(int l, int r) {
    if (r-l == 1) return v[l];
    int m = l + (r-l)/2;
    return convolution(rec(l, m), rec(m, r));
}

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
        v.push_back({1, A[i]});
    }
    vector<mint> F = rec(0, N);
    mint c = sum;
    mint ans = 2;
    for (int k = 3; k <= N+1; k++) {
        c *= (mint)(sum-(k-2))*(((mint)(k-1)).inv());
        ans += F[k-1]*c.inv();
    }
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
