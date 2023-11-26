// https://atcoder.jp/contests/abc167/tasks/abc167_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> P(1e+6, 1), Q(1e+6, 1);
vector<mint> F(1e+6, 1);
mint C(int n, int r) {return F[n]/(F[n-r]*F[r]);}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int x = 1; x < 1e+6; x++) F[x] = F[x-1] * x;
    for (int x = 1; x < 1e+6; x++) P[x] = P[x-1] * M;
    for (int x = 1; x < 1e+6; x++) Q[x] = Q[x-1] * (M-1);

    mint ans = P[N];
    for (int k = K+1; k < N; k++) {
        ans -= C(N-1, k) * M * Q[N-k-1];
    }

    cout << ans.val() << endl;
}
