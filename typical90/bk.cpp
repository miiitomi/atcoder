#include <bits/stdc++.h>
using namespace std;

int f(int b, int H, int W, vector<vector<int>> &P) {
    map<int, int> M;
    for (int w = 0; w < W; w++) {
        int p = -1;
        bool ok = true;

        for (int h = 0; h < H; h++) {
            if ((1 << h) & b) {
                if (p == -1) {
                    p = P[h][w];
                } else if (p != P[h][w]) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) M[p]++;
    }

    int m = 0;
    for (auto x : M) m = max(m, x.second);

    int n = 0;
    while (b > 0) {
        n += b % 2;
        b /= 2;
    }

    return m * n;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> P[i][j];
    }

    int ans = 0;
    for (int b = 1; b < (1 << H); b++) {
        ans = max(ans, f(b, H, W, P));
    }
    cout << ans << endl;
}
