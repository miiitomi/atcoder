// https://atcoder.jp/contests/abc321/tasks/abc321_g
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> F((int)1e+6, 1);

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> R(M), B(M);
    vector<int> cnt_R(N, 0), cnt_B(N, 0);
    for (int i = 0; i < M; i++) {
        cin >> R[i];
        R[i]--;
        cnt_R[R[i]]++;
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        B[i]--;
        cnt_B[B[i]]++;
    }
    mint ans = 0;
    vector<mint> f((1 << N), 1), g((1 << N), 1);
    for (int s = 1; s < (1 << N); s++) {
        int cnt = 0, r = 0, b = 0, a = 0;
        for (int i = 0; i < N; i++) {
            if (!(s & (1 << i))) continue;
            cnt++;
            r += cnt_R[i];
            b += cnt_B[i];
            a = i;
        }
        if (r != b) {
            f[s] = 0;
            g[s] = 0;
            continue;
        }
        f[s] = F[r];
        g[s] = f[s];

        for (int t = (s - 1) & s; t > 0; t = (t-1) & s) {
            if (!(t & (1 << a))) continue;
            g[s] -= g[t] * f[s & (~t)];
        }
        ans += g[s] * F[M-r];
    }
    ans /= F[M];
    cout << ans.val() << endl;
}

int main() {
    for (int x = 2; x < (int)1e+6; x++) F[x] = F[x-1] * x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
