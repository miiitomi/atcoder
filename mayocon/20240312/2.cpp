// https://atcoder.jp/contests/abc339/tasks/abc339_b
#include <bits/stdc++.h>
using namespace std;

vector<int> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};

void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<string> S(H, string(W, '.'));
    int x = 0, y = 0, k = 0;
    while (N--) {
        if (S[x][y] == '.') {
            S[x][y] = '#';
            k = (k + 1) % 4;
            x = (x + dx[k] + H) % H;
            y = (y + dy[k] + W) % W;
        } else {
            S[x][y] = '.';
            k = (k + 3) % 4;
            x = (x + dx[k] + H) % H;
            y = (y + dy[k] + W) % W;
        }
    }
    for (string s : S) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
