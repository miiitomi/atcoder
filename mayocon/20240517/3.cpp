// https://atcoder.jp/contests/abc173/tasks/abc173_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> c(H);
    for (int i = 0; i < H; i++) cin >> c[i];

    int ans = 0;
    for (int h = 0; h < (1 << H); h++) {
        for (int w = 0; w < (1 << W); w++) {
            int cnt = 0;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (c[i][j] == '.') continue;
                    if ((h & (1 << i)) || (w & (1 << j))) continue;
                    cnt++;
                }
            }
            if (cnt == K) ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
