// https://atcoder.jp/contests/abc109/tasks/abc109_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0));
    vector<vector<int>> V;
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] % 2 == 0 || (i == H-1 && j == W-1)) continue;
            if (j < W-1) {
                A[i][j]--;
                A[i][j+1]++;
                V.push_back(vector<int>{i, j, i, j+1});
            } else {
                A[i][j]--;
                A[i+1][j]++;
                V.push_back(vector<int>{i, j, i+1, j});
            }
        }
    }
    cout << V.size() << "\n";
    for (auto a : V) {
        cout << a[0]+1 << " " << a[1]+1 << " " << a[2]+1 << " " << a[3]+1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
