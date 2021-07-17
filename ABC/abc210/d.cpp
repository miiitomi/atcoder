#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, C;
    cin >> H >> W >> C;
    vector<vector<int64_t>> A(H, vector<int64_t >(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> A[h][w];
        }
    }

    vector<vector<int64_t>> dp1(H, vector<int64_t >(W, (1LL << 50)));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            dp1[h][w] = min(dp1[h][w], A[h][w]);
            if (w > 0) dp1[h][w] = min(dp1[h][w], dp1[h][w-1] + C);
            if (h > 0) dp1[h][w] = min(dp1[h][w], dp1[h-1][w] + C);
        }
    }
    vector<vector<int64_t>> X(H, vector<int64_t >(W, (1LL << 50)));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (w > 0) X[h][w] = min(X[h][w], dp1[h][w-1] + C + A[h][w]);
            if (h > 0) X[h][w] = min(X[h][w], dp1[h-1][w] + C + A[h][w]);
        }
    }

    vector<vector<int64_t>> dp2(H, vector<int64_t >(W, (1LL << 50)));
    for (int h = 0; h < H; h++) {
        for (int w = W - 1; w >= 0; w--) {
            dp2[h][w] = min(dp2[h][w], A[h][w]);
            if (w < W - 1) dp2[h][w] = min(dp2[h][w], dp2[h][w+1] + C);
            if (h > 0) dp2[h][w] = min(dp2[h][w], dp2[h-1][w] + C);
        }
    }
    vector<vector<int64_t>> Y(H, vector<int64_t >(W, (1LL << 50)));
    for (int h = 0; h < H; h++) {
        for (int w = W - 1; w >= 0; w--) {
            if (w < W - 1) Y[h][w] = min(Y[h][w], dp2[h][w+1] + C + A[h][w]);
            if (h > 0) Y[h][w] = min(Y[h][w], dp2[h-1][w] + C + A[h][w]);
        }
    }

    int64_t ans = (1LL << 50);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            ans = min(ans, X[h][w]);
            ans = min(ans, Y[h][w]);
        }
    }

    cout << ans << endl;
}
