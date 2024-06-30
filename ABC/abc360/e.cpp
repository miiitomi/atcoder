#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;

mint N;
mint NN_inv;

mint f(mint p) {
    mint np = (((N-1)*(N-1) + 1)*p + 2*(1-p)) * NN_inv;
    return np;
}

void solve() {
    int n, K;
    cin >> n >> K;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    N = n;
    NN_inv = (((mint)N)*N).inv();
    mint p = 1;
    while (K--) p = f(p);

    mint ans = p + ((N+2)*(N-1)/2) * ((1-p)/(N-1));
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
