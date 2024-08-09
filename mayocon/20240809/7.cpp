// https://atcoder.jp/contests/abc276/tasks/abc276_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F;
mint comb(int n, int r) {return F[n]/(F[n-r]*F[r]);}
vector<mint> S;
ll N, M;

void preprocessing() {
    F.assign(N+M/3, 1);
    for (int x = 1; x < (int)F.size(); x++) F[x] = x*F[x-1];
    S.assign(M/3+1, 1);
    for (int t = 1; t < (int)S.size(); t++) S[t] = S[t-1] + comb(N-1+t, N-1);
}

void solve() {
    cin >> N >> M;
    preprocessing();

    mint ans = 0;
    for (int x1 = 0; x1 <= 2; x1++) {
        for (int y = 0; y <= N-1; y++) {
            int T = x1 + y + (N-1-y)*2;
            if (T > M) continue;
            mint tmp = comb(N-1, y);
            ans += tmp*S[(M-T)/3];
        }
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
