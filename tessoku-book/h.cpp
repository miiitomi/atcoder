#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> X(H, vector<int>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> X[h][w];
        }
    }

    vector<vector<int>> S(H, vector<int>(W));
    S[0][0] = X[0][0];
    for (int w = 1; w < W; w++) {
        S[0][w] = S[0][w-1] + X[0][w];
    }
    for (int h = 1; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (w == 0) {
                S[h][w] = S[h-1][w] + X[h][w];
            } else {
                S[h][w] = S[h][w-1] + S[h-1][w] - S[h-1][w-1] + X[h][w];
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        int ans = S[c][d];
        if (b > 0) ans -= S[c][b-1];
        if (a > 0) ans -= S[a-1][d];
        if (a > 0 && b > 0) ans += S[a-1][b-1];
        cout << ans << endl;
    }
}
