// https://atcoder.jp/contests/abc096/tasks/abc096_c
#include <bits/stdc++.h>
using namespace std;

int H, W;
bool is_in(int i, int j) {return 0 <= i && i < H && 0 <= j && j < W;}
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};


int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] == '.') continue;
            bool ok = false;
            for (int k = 0; k < 4; k++) {
                int x = h + dx[k], y = w + dy[k];
                if (is_in(x, y) && S[x][y] == '#') ok = true;
            }
            if (!ok) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
