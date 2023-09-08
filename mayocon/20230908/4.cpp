// https://atcoder.jp/contests/abc317/tasks/abc317_e
#include <bits/stdc++.h>
using namespace std;

vector<int> dx{1, -1, 0, 0};
vector<int> dy{0, 0, 1, -1};
int H, W;

bool in_range(int i, int j) {
    return (0 <= i && i < H && 0 <= j && j < W);
}

int to_int(int i, int j) {
    return W*i + j;
}

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    set<int> NG;
    vector<vector<int>> G(H*W);

    int s = -1;
    int g = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            else if (S[i][j] == '>') {
                int _j = j+1;
                while (in_range(i, _j) && S[i][_j] == '.') {
                    NG.insert(to_int(i, _j));
                    _j++;
                }
            } else if (S[i][j] == '<') {
                int _j = j-1;
                while (in_range(i, _j) && S[i][_j] == '.') {
                    NG.insert(to_int(i, _j));
                    _j--;
                }                
            } else if (S[i][j] == '^') {
                int _i = i-1;
                while (in_range(_i, j) && S[_i][j] == '.') {
                    NG.insert(to_int(_i, j));
                    _i--;
                }
            } else if (S[i][j] == 'v') {
                int _i = i+1;
                while (in_range(_i, j) && S[_i][j] == '.') {
                    NG.insert(to_int(_i, j));
                    _i++;
                }
            } else {
                if (S[i][j] == 'S') s = to_int(i, j);
                else if (S[i][j] == 'G') g = to_int(i, j);
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (in_range(x, y) && (S[x][y] == '.' || S[x][y] == 'G')) {
                        G[to_int(i,j)].push_back(to_int(x, y));
                    }
                }
            }
        }
    }

    vector<int> d(H*W, 1e+9);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] < 1e+9 || NG.count(w)) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }

    if (d[g] < 1e+9) cout << d[g] << endl;
    else cout << -1 << endl;
}
