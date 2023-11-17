// https://atcoder.jp/contests/abc293/tasks/abc293_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];

    int ans = 0;
    vector<int> v(H+W-2, 0);
    for (int i = 0; i < W-1; i++) v[(int)v.size()-1-i] = 1;

    do {
        unordered_set<int> S;
        int x = 0, y = 0;
        S.insert(A[x][y]);
        bool ok = true;
        for (int t : v) {
            if (t == 0) x++;
            else y++;
            if (S.count(A[x][y])) {
                ok = false;
                break;
            } else S.insert(A[x][y]);
        }
        if (ok) ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
