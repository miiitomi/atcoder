#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<int> S(H, 0), T(W, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            S[i] += A[i][j];
            T[j] += A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << S[i] + T[j] - A[i][j];
            if (j < W-1) cout << " ";
            else cout << endl;
        }
    }
}
