#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}
const int INF = 1e+9;

void solve() {
    cin >> H >> W;
    vector<string> A(H);
    pair<int,int> s, t;
    for (int h = 0; h < H; h++) {
        cin >> A[h];
        for (int w = 0; w < W; w++) {
            if (A[h][w] == 'S') s = {h, w};
            if (A[h][w] == 'T') t = {h, w};
        }
    }

    int N;
    cin >> N;
    N += 2;
    vector<int> R(N, 0), C(N, 0), E(N, 0);
    for (int i = 0; i < N-2; i++) {
        cin >> R[i] >> C[i] >> E[i];
        R[i]--;
        C[i]--;
    }
    R[N-2] = s.first;
    C[N-2] = s.second;
    R[N-1] = t.first;
    C[N-1] = t.second;
    vector<vector<int>> G(N);
    for (int i = 0; i < N; i++) {
        vector<vector<int>> d(H, vector<int>(W, INF));
        d[R[i]][C[i]] = 0;
        queue<pair<int,int>> Q;
        Q.push(make_pair(R[i], C[i]));
        while (!Q.empty()) {
            pair<int,int> p = Q.front();
            Q.pop();
            for (int k = 0; k < 4; k++) {
                int x = p.first + dx[k], y = p.second + dy[k];
                if (is_in(x, y) && d[x][y] == INF && A[x][y] != '#') {
                    d[x][y] = d[p.first][p.second] + 1;
                    Q.push(make_pair(x, y));
                }
            }
        }
        for (int j = 0; j < N; j++) {
            if (j != i && d[R[j]][C[j]] <= E[i]) G[i].push_back(j);
        }
    }

    vector<bool> reached(N, false);
    reached[N-2] = true;
    queue<int> Q;
    Q.push(N-2);
    while (!Q.empty()) {
        int i = Q.front();
        Q.pop();
        for (int j : G[i]) {
            if (!reached[j]) {
                reached[j] = true;
                Q.push(j);
            }
        }
    }

    if (reached.back()) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
