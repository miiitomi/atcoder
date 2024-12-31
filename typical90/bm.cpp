#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(2e+5 + 1, 1), I(2e+5 + 1, 1);
mint C(int n, int r) {return F[n]*I[n-r]*I[r];}

void solve() {
    ll R, G, B, K, X, Y, Z;
    cin >> R >> G >> B >> K >> X >> Y >> Z;
    ll r = K - Y, g = K - Z, b = K - X;
    vector<mint> S(R+1, 0), T(G+1, 0);
    for (int x = r; x <= R; x++) S[x] = C(R, x);
    for (int x = g; x <= G; x++) T[x] = C(G, x);
    vector<mint> U = convolution(S, T);
    mint ans = 0;
    for (int u = 0; u < (int)U.size(); u++) {
        int x = K - u;
        if (x < b || B < x) continue;
        ans += U[u] * C(B, x);
    }
    cout << ans.val() << "\n";
}

int main() {
    for (int x = 1; x <= 2e+5; x++) {
        F[x] = F[x-1]*x;
        I[x] = F[x].inv();
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
