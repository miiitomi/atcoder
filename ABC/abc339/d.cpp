#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    H = N;
    W = N;
    int s = -1, t = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'P') {
                if (s == -1) s = to_int(i, j);
                else t = to_int(i, j);
            }
        }
    }
    vector<vector<int>> d(N*N, vector<int>(N*N, -1));
    queue<pair<int,int>> Q;
    d[s][t] = 0;
    Q.push(make_pair(s, t));

    while (!Q.empty()) {
        int a = Q.front().first, b = Q.front().second;
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int u = a, v = b;
            int l = to_xy(a).first + dx[k], r = to_xy(a).second + dy[k];
            if (is_in(l, r) && S[l][r] != '#') u = to_int(l, r);
            l = to_xy(b).first + dx[k];
            r = to_xy(b).second + dy[k];
            if (is_in(l, r) && S[l][r] != '#') v = to_int(l, r);

            if (u == v) {
                cout << d[a][b] + 1 << "\n";
                return;
            } else if (d[u][v] < 0) {
                d[u][v] = d[a][b] + 1;
                Q.push(make_pair(u, v));
            }
        }
    }

    cout << -1 << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
