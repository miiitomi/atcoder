// https://atcoder.jp/contests/abc246/tasks/abc246_e
#include <bits/stdc++.h>
using namespace std;

int N;
bool is_in(int x, int y) {return 0 <= x && x < N && 0 <= y && y < N;}
vector<int> dx{1, 1, -1, -1}, dy{1, -1, 1, -1};

void solve() {
    cin >> N;
    vector<string> S(N);
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    ax--; ay--; bx--; by--;
    for (int i = 0; i < N; i++) cin >> S[i];
    if ((ax + ay) % 2 != (bx + by) % 2) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> d(N, vector<int>(N, -1));
    d[ax][ay] = 0;
    queue<pair<int,int>> Q;
    Q.push({ax, ay});

    while (!Q.empty()) {
        auto [px, py] = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int x = px + dx[k], y = py + dy[k];
            while (is_in(x, y) && S[x][y] == '.') {
                if (d[x][y] == -1) {
                    d[x][y] = d[px][py] + 1;
                    Q.push({x,y});
                    if (x == bx && y == by) {
                        cout << d[x][y] << "\n";
                        return;
                    }
                }
                x += dx[k];
                y += dy[k];
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
