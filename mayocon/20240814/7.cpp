// https://atcoder.jp/contests/abc321/tasks/abc321_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(2e+5, 1);

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> r(N, 0), b(N, 0);
    for (int i = 0; i < M; i++) {
        int R;
        cin >> R;
        r[R-1]++;
    }
    for (int i = 0; i < M; i++) {
        int B;
        cin >> B;
        b[B-1]++;
    }
    vector<mint> f(1 << N, 0), g(1 << N, 0);
    mint ans = 0;
    for (ll s = 1; s < (1 << N); s++) {
        ll R = 0, B = 0;
        ll a = -1;
        for (int i = 0; i < N; i++) {
            if (s & (1 << i)) {
                R += r[i];
                B += b[i];
                if (a == -1) a = i;
            }
        }
        if (R != B) continue;
        f[s] = F[R];
        g[s] = f[s];
        for (ll t = (s-1); t >= 1; t = (t-1)&s) {
            if (!(t & (1 << a))) continue;
            g[s] -= g[t]*f[s-t];
        }
        ans += g[s] * F[M-R];
    }
    ans *= F[M].inv();
    cout << ans.val() << "\n";
}

int main() {
    for (int x = 1; x < 2e+5; x++) F[x] = x * F[x-1];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
