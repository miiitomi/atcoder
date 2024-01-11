// https://atcoder.jp/contests/abc129/tasks/abc129_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> R(H), C(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                R[i].push_back(j);
                C[j].push_back(i);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            int tmp = -1;

            if (R[i].empty()) {
                tmp += W;
            } else {
                auto iter1 = lower_bound(R[i].begin(), R[i].end(), j);
                int s, t;
                if (iter1 == R[i].begin()) s = 0;
                else {
                    iter1--;
                    s = *iter1 + 1;
                    iter1++;
                }
                if (iter1 == R[i].end()) t = W-1;
                else t = *iter1 - 1;
                tmp += (t - s + 1);
            }

            if (C[j].empty()) {
                tmp += H;
            } else {
                auto iter1 = lower_bound(C[j].begin(), C[j].end(), i);
                int s, t;
                if (iter1 == C[j].begin()) s = 0;
                else {
                    iter1--;
                    s = *iter1 + 1;
                    iter1++;
                }
                if (iter1 == C[j].end()) t = H-1;
                else t = *iter1 - 1;
                tmp += (t - s + 1);
            }

            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}
