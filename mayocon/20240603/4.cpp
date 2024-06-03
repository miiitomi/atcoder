// https://atcoder.jp/contests/abc129/tasks/abc129_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    vector<set<int>> R(H+1);
    vector<set<int>> C(W+1);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        R[i+1].insert(0);
        R[i+1].insert(W+1);
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') R[i+1].insert(j+1);
        }
    }
    for (int j = 0; j < W; j++) {
        C[j+1].insert(0);
        C[j+1].insert(H+1);
        for (int i = 0; i < H; i++) {
            if (S[i][j] == '#') C[j+1].insert(i+1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (S[i-1][j-1] == '#') continue;
            int tmp = -1;
            auto iter1 = R[i].lower_bound(j);
            int r = *iter1;
            iter1--;
            int l = *iter1;
            tmp += r-l-1;
            auto iter2 = C[j].lower_bound(i);
            r = *iter2;
            iter2--;
            l = *iter2;
            tmp += r-l-1;
            ans = max(ans, tmp);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
