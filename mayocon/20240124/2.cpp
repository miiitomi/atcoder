// https://atcoder.jp/contests/abc300/tasks/abc300_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H), B(H);
    for (int i = 0; i < H; i++) cin >> A[i];
    for (int i = 0; i < H; i++) cin >> B[i];

    for (int s = 0; s < H; s++) {
        for (int t = 0; t < W; t++) {
            vector<string> C = A;
            for (int p = 0; p < s; p++) {
                vector<string> D = C;
                for (int i = 0; i < H; i++) {
                    for (int j = 0; j < W; j++) {
                        D[(i+1)%H][j] = C[i][j];
                    }
                }
                swap(C, D);
            }
            for (int q = 0; q < t; q++) {
                vector<string> D = C;
                for (int i = 0; i < H; i++) {
                    for (int j = 0; j < W; j++) {
                        D[i][(j+1)%W] = C[i][j];
                    }
                }
                swap(C, D);
            }

            if (C == B) {
                cout << "Yes" << endl;
                return;
            }
        }
    }

    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
