// https://atcoder.jp/contests/abc075/tasks/abc075_b
#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (S[x][y] == '#') continue;
            int cnt = 0;
            for (int i = x-1; i <= x+1; i++) {
                for (int j = y-1; j <= y+1; j++) {
                    if (is_in(i, j) && S[i][j] == '#') cnt++; 
                }
            }
            S[x][y] = '0' + cnt;
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
