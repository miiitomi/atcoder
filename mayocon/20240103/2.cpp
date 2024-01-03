// https://atcoder.jp/contests/abc302/tasks/abc302_b
#include <bits/stdc++.h>
using namespace std;

string snuke = "snuke";

int H, W;
vector<vector<int>> dx{
    {0, 1, 2, 3, 4},
    {0, -1, -2, -3, -4},
    {0, 0, 0, 0, 0}
};
vector<vector<int>> dy{
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, -1, -2, -3, -4}
};

bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (auto v : dx) {
                for (auto w : dy) {
                    bool ok = true;
                    for (int k = 0; k < 5; k++) {
                        int x = i + v[k], y = j + w[k];
                        if (!is_in(x, y) || snuke[k] != S[x][y]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        for (int k = 0; k < 5; k++) {
                            int x = i + v[k], y = j + w[k];
                            cout << x+1 << " " << y+1 << "\n";
                        }
                        return 0;
                    }
                }
            }
        }
    }
}
