// https://atcoder.jp/contests/abc156/tasks/abc156_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> F(1e+6, 1);
mint C(int n, int r) {return F[n] / (F[n-r]*F[r]);}
mint H(int n, int r) {return C(n+r-1, r);}

int main() {
    for (int x = 2; x < 1e+6; x++) F[x] = F[x-1] * x;

    int N, K;
    cin >> N >> K;
    mint ans = 0;
    for (int m = 0; m <= min(N-1, K); m++) {
        ans += C(N, m) * H(N-m, m);
    }

    cout << ans.val() << endl;
}
