// https://atcoder.jp/contests/abc191/tasks/abc191_c
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{-1, -1, 0, 0}, dy{-1, 0, -1, 0};

bool is_in(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    int ans = 0;
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            if ((i == 0 || i == H) && (j == 0 || j == W)) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y)) continue;
                if (S[x][y] == '#') cnt++;
            }
            if (cnt & 1 == 1) ans++;
        }
    }

    cout << ans << endl;
}
