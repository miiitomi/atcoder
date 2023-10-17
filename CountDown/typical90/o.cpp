#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

vector<mint> F;

mint C(int n, int r) {
    return F[n] / (F[n-r] * F[r]);
}

int main() {
    int N;
    cin >> N;

    F.assign(N+1, 1);
    for (int i = 1; i <= N; i++) F[i] = F[i-1]*i;

    for (int k = 1; k <= N; k++) {
        mint ans = 0;
        for (int a = 1; N - (k-1)*(a-1) >= a; a++) {
            ans += C(N - (k-1)*(a-1), a);
        }
        cout << ans.val() << endl;
    }
}
