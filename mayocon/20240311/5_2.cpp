// https://atcoder.jp/contests/abc196/tasks/abc196_d
#include <bits/stdc++.h>
using namespace std;

int H, W, A, B, N, ans = 0;

void dfs(int i, int s, int a, int b) {
    if (i == N && a == 0 && b == 0) {
        ans++;
        return;
    }
    if (s & (1 << i)) {
        dfs(i+1, s, a, b);
        return;
    }
    if (b > 0) dfs(i+1, s + (1 << i), a, b-1);
    if (a > 0) {
        if (i % W != W-1 && !(s & (1 << (i+1)))) dfs(i+1, s + (1 << i) + (1 << (i+1)), a-1, b);
        if (i + W < N && !(s & (1 << (i+W)))) dfs(i+1, s + (1 << i) + (1 << (i+W)), a-1, b);
    }
}

void solve() {
    cin >> H >> W >> A >> B;
    N = H*W;
    dfs(0, 0, A, B);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
