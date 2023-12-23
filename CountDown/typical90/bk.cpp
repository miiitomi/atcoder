#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> P[i][j];

    int ans = 0;
    for (int s = 1; s < (1 << H); s++) {
        vector<int> cnt(H*W+1, 0);
        int c = 0;
        for (int i = 0; i < H; i++) if (s & (1 << i)) c++;
        for (int j = 0; j < W; j++) {
            bool ok = true;
            int v = -1;
            for (int i = 0; i < H; i++) {
                if (!(s & (1 << i))) continue;
                if (v == -1) v = P[i][j];
                else if (v != P[i][j]) ok = false;
            }
            if (ok) cnt[v]++;
        }
        ans = max(ans, c * (*max_element(cnt.begin(), cnt.end())));
    }
    cout << ans << endl;
}
