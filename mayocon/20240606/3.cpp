// https://atcoder.jp/contests/abc264/tasks/abc264_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H1, W1, H2, W2;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    for (int i = 0; i < H1; i++) for (int j = 0; j < W1; j++) cin >> A[i][j];
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    for (int i = 0; i < H2; i++) for (int j = 0; j < W2; j++) cin >> B[i][j];

    for (int s = 0; s < (1 << H1); s++) {
        vector<int> v;
        for (int i = 0; i < H1; i++) if (s & (1 << i)) v.push_back(i);
        if ((int)v.size() != H2) continue;
        for (int t = 0; t < (1 << W1); t++) {
            vector<int> w;
            for (int j = 0; j < W1; j++) if (t & (1 << j)) w.push_back(j);
            if ((int)w.size() != W2) continue;

            vector<vector<int>> C(H2, vector<int>(W2));
            for (int i = 0; i < H2; i++) {
                for (int j = 0; j < W2; j++) {
                    C[i][j] = A[v[i]][w[j]];
                }
            }

            if (C == B) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
