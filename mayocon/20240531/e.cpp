// https://atcoder.jp/contests/abc341/tasks/abc341_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            int x = i, y = j;
            bool is_ok = true;
            for (char t : T) {
                if (t == 'L') y--;
                else if (t == 'R') y++;
                else if (t == 'U') x--;
                else if (t == 'D') x++;
                if (S[x][y] == '#') {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) ans++;
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
