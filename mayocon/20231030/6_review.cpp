// https://atcoder.jp/contests/abc301/tasks/abc301_e
#include <bits/stdc++.h>
using namespace std;

int H, W, T;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

int main() {
    cin >> H >> W >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int s, g;
    vector<int> o;
    vector<vector<int>> G(H*W);
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            int i = to_int(x, y);
            if (S[x][y] == '#') continue;
            else if (S[x][y] == 'S') s = i;
            else if (S[x][y] == 'G') g = i;
            else if (S[x][y] == 'o') o.push_back(i);

            for (int k = 0; k < 4; k++) {
                int a = x+dx[k], b = y+dy[k];
                if (!is_in(a, b) || S[a][b] == '#') continue;
                int j = to_int(a, b);
                G[i].push_back(j);
            }
        }
    }

    o.push_back(s);
    o.push_back(g);
    int O = o.size() - 2;

    vector<vector<int>> d(o.size(), vector<int>(o.size(), 1e+9));
    for (int i = 0; i < (int)o.size(); i++) {
        vector<int> D(H*W, 1e+9);
        int p = o[i];
        D[p] = 0;
        queue<int> Q;
        Q.push(p);
        while (!Q.empty()) {
            int p = Q.front();
            Q.pop();
            for (int q : G[p]) {
                if (D[q] != 1e+9) continue;
                D[q] = D[p] + 1;
                Q.push(q);
            }
        }
        for (int j = 0; j < (int)o.size(); j++) d[i][j] = D[o[j]];
    }

    if (O == 0) {
        if (d[0][1] <= T) cout << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> dp((1 << O), vector<int>(O, 1e+9));
    dp[0].assign(O, d[O][O+1]);
    for (int s = 0; s < (1 << O); s++) {
        if (s == 0) {
            for (int p = 0; p < O; p++) {
                dp[(1 << p)][p] = min(dp[(1 << p)][p], d[O][p] + d[p][O+1]);
            }
            continue;
        }
        for (int p = 0; p < O; p++) {
            if (!(s & (1 << p)) || dp[s][p] == (int)1e+9) continue;
            for (int q = 0; q < O; q++) {
                if (s & (1 << q) || d[p][q] == (int)1e+9) continue;
                int tmp = dp[s][p] - d[p][O+1] + d[p][q] + d[q][O+1];
                dp[s + (1 << q)][q] = min(dp[s + (1 << q)][q], tmp);
            }
        }
    }

    int ans = -1;
    for (int s = 0; s < (1 << O); s++) {
        int cnt = 0;
        for (int p = 0; p < O; p++) cnt += (bool)(s & (1 << p));
        if (*min_element(dp[s].begin(), dp[s].end()) <= T) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}
