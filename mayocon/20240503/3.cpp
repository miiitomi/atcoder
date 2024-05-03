// https://atcoder.jp/contests/abc300/tasks/abc300_c
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> S;
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
vector<int> dx{1, 1, -1, -1}, dy{1, -1, 1, -1};


int f(int i, int j) {
    if (S[i][j] == '.') return 0;
    int cnt = 0;
    for (int k = 1; true; k++) {
        for (int l = 0; l < 4; l++) {
            int x = i + k*dx[l], y = j + k*dy[l];
            if (!is_in(x, y) || S[x][y] == '.') return cnt;
        }
        cnt++;
    }
}

void solve() {
    cin >> H >> W;
    S.resize(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<int> X(min(H, W), 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int tmp = f(i, j);
            if (tmp) {
                X[tmp-1]++;
            }
        }
    }

    for (int x : X) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
