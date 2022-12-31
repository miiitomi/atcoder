#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<vector<int>> A(H+2, vector<int>(W+2, 0));
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A[a][b]++;
        A[a][d+1]--;
        A[c+1][b]--;
        A[c+1][d+1]++;
    }

    for (int h = 1; h < H+2; h++) {
        for (int w = 1; w < W+2; w++) {
            A[h][w] = A[h][w-1] + A[h][w];
        }
    }

    for (int w = 1; w < W+2; w++) {
        for (int h = 1; h < H+2; h++) {
            A[h][w] = A[h-1][w] + A[h][w];
        }
    }

    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            cout << A[h][w];
            if (w == W) cout << endl;
            else cout << " ";
        }
    }
}
