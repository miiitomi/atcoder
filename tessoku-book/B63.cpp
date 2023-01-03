#include <bits/stdc++.h>
using namespace std;

vector<int> dy{1, -1, 0, 0};
vector<int> dx{0, 0, 1, -1};

int main() {
    int R, C;
    cin >> R >> C;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    vector<string> c(R);
    for (int i = 0; i < R; i++) cin >> c[i];

    vector<vector<int> > dist(R, vector<int>(C, -1));
    dist[sy][sx] = 0;
    queue<pair<int, int> > Q;
    Q.push(make_pair(sy, sx));

    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> q = make_pair(p.first + dy[i], p.second + dx[i]);
            if (0 <= q.first && q.first < R && 0 <= q.second && q.second < C) {
                if (c[q.first][q.second] == '#' || dist[q.first][q.second] != -1) continue;
                Q.push(q);
                dist[q.first][q.second] = dist[p.first][p.second] + 1;
            }
        }
    }

    cout << dist[gy][gx] << endl;
}
