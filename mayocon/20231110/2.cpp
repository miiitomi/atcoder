// https://atcoder.jp/contests/abc075/tasks/abc075_b
#include <bits/stdc++.h>
using namespace std;

int H, W;
bool is_in(int i, int j) {return 0 <= i && i < H && 0 <= j && j < W;}
vector<int> vx{-1, 0, 1, -1, 1, -1, 0, 1}, vy{-1, -1, -1 ,0, 0, 1, 1, 1};

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] != '.') continue;
            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + vx[k], y = j + vy[k];
                if (is_in(x, y) && S[x][y] == '#') cnt++;
            }
            S[i][j] = (char)(cnt + '0');
        }
    }

    for (string s : S) cout << s << endl;
}
