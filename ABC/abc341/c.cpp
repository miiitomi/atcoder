#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    set<pair<int,int>> st;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            bool ok = true;
            int x = i, y = j;
            for (int k = 0; k < N; k++) {
                if (T[k] == 'L') y--;
                if (T[k] == 'R') y++;
                if (T[k] == 'U') x--;
                if (T[k] == 'D') x++;

                if (S[x][y] == '#') {
                    ok = false;
                    break;
                }
            }
            if (ok) st.insert(make_pair(x, y));
        }
    }

    cout << st.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
