// https://atcoder.jp/contests/abc113/tasks/abc113_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<int> S;
    for (int i = 0; i < (1 << (W-1)); i++) {
        bool ok = true;
        for (int j = 1; j < W-1; j++) {
            if ((i & (1 << (j-1))) && (i & (1 << j))) ok = false;
        }
        if (ok) S.push_back(i);
    }

    vector<vector<ll>> dp(H+1, vector<ll>(W, 0));
    dp[0][0] = 1;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            int to_l = 0;
            int to_s = 0;
            int to_r = 0;
            for (int i : S) {
                if ((w > 0) && (i & (1 << (w-1)))) to_l++;
                else if ((w < W-1) && (i & (1 << w))) to_r++;
                else to_s++;
            }
            if (to_l > 0) dp[h+1][w-1] = (dp[h+1][w-1] + (dp[h][w] * to_l) % MOD) % MOD;
            if (to_r > 0) dp[h+1][w+1] = (dp[h+1][w+1] + (dp[h][w] * to_r) % MOD) % MOD;
            dp[h+1][w] = (dp[h+1][w] + (dp[h][w] * to_s) % MOD) % MOD;
        }
    }

    cout << dp[H][K-1] << endl;
}
