// https://atcoder.jp/contests/abc205/tasks/abc205_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> F(1e+7, 1);
mint C(int n, int r) {
    if (min(n-r, r) < 0) return 0;
    return F[n]/ (F[n-r]*F[r]);
}

int main() {
    for (int x = 1; x < 1e+7; x++) F[x] = F[x-1] * x;

    int N, M, K;
    cin >> N >> M >> K;

    if (N >= M+K+1) {
        cout << 0 << endl;
        return 0;
    }

    int s = M - (-K-1), t = N - (K+1);
    mint ans = C(N+M, N) - C(s+t, s);

    cout << ans.val() << endl;
}
