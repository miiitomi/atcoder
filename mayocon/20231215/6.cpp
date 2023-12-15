// https://atcoder.jp/contests/abc262/tasks/abc262_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> F(1e+6, 1);
mint C(int n, int r) {return F[n]*(F[n-r]*F[r]).inv();}

int main() {
    for (int x = 1; x < 1e+6; x++) F[x] = F[x-1] * x;

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> cnt(N, 0);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cnt[u]++;
        cnt[v]++;
    }

    int odd=0, even=0;
    for (int i = 0; i < N; i++) {
        if (cnt[i] % 2 == 0) even++;
        else odd++;
    }

    mint ans = 0;
    for (int x = 0; x <= odd; x += 2) {
        int y = K - x;
        if (y < 0 || y > even) continue;
        ans += C(odd, x)*C(even, y);
    }

    cout << ans.val() << endl;
}
