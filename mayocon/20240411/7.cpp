// https://atcoder.jp/contests/abc215/tasks/abc215_g
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> F(1e+5, 1);
mint C(int n, int r) {
    if (r > n) return 0;
    return F[n] / (F[n-r]*F[r]);
}

void solve() {
    int N;
    cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; i++) cin >> c[i];
    sort(c.begin(), c.end());
    vector<int> cnt(N+1, 0);
    int tmp = -1, tmp_cnt=0;
    for (int i = 0; i < N; i++) {
        if (tmp != c[i]) {
            if (tmp > 0) cnt[tmp_cnt]++;
            tmp = c[i];
            tmp_cnt=0;
        }
        tmp_cnt++;
    }
    cnt[tmp_cnt]++;

    vector<mint> C_N_k(N+1, 0);
    for (int k = 1; k <= N; k++) C_N_k[k] = C(N, k);

    vector<mint> ans(N+1, 0);
    for (int n = 1; n <= N; n++) {
        if (cnt[n] == 0) continue;
        for (int k = 1; k <= N; k++) {
            ans[k] += (C_N_k[k] - C(N-n, k)) * cnt[n];
        }
    }

    for (int k = 1; k <= N; k++) {
        cout << (ans[k] / C_N_k[k]).val() << "\n";
    }
}

int main() {
    for (int x = 1; x < 1e+5; x++) F[x] = F[x-1] * x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
