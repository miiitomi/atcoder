// https://atcoder.jp/contests/abc253/tasks/abc253_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    pair<int,int> p = {-1, -1}, q = {-1, -1};
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (S[x][y] == '-') continue;
            if (p.first == -1) p = {x, y};
            else q = {x, y};
        }
    }

    cout << abs(p.first - q.first) + abs(p.second - q.second) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
