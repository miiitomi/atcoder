#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> A[i][j];
    }

    string S = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << S[A[i][j]];
            if (j == W-1) cout << endl;
        }
    }
}
