// https://atcoder.jp/contests/abc127/tasks/abc127_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;

vector<mint> F(1e+6, 1);

mint C(int n, int r) {
    return F[n] / (F[n-r] * F[r]);
}


mint f(ll N, ll M, ll K) {
    mint ans = 0;
    for (ll d = 1; d <= N-1; d++) {
        ans += d * (N - d);
    }
    ans *= M * M * C(N*M-2, K-2);
    return ans;
}

int main() {
    for (int x = 1; x < 1e+6; x++) F[x] = F[x-1] * x;
    ll N, M, K;
    cin >> N >> M >> K;
    mint ans = f(N, M, K) + f(M, N, K);
    cout << ans.val() << endl;
}
