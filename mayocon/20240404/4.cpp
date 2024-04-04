// https://atcoder.jp/contests/abc191/tasks/abc191_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int cnt = 0;
    for (int x = 0; x < H-1; x++) {
        for (int y = 0; y < W-1; y++) {
            int tmp = 0;
            if (S[x][y] == '#') tmp++;
            if (S[x+1][y] == '#') tmp++;
            if (S[x][y+1] == '#') tmp++;
            if (S[x+1][y+1] == '#') tmp++;
            if (tmp % 2 == 1) cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
