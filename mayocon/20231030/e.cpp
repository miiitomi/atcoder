// https://atcoder.jp/contests/abc301/tasks/abc301_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W, T;
vector<string> A;

vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};

bool is_in(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

int main() {
    cin >> H >> W >> T;
    A.resize(H);
    for (int i = 0; i < H; i++) cin >> A[i];

    int sx, sy, gx, gy;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (A[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }

    vector<pair<int,int>> v{make_pair(sx, sy)};
    map<pair<int,int>, int> mp{{make_pair(sx, sy), 0}};
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'o') {
                cnt++;
                v.push_back(make_pair(i, j));
                mp[make_pair(i, j)] = cnt;
            }
        }
    }
    mp[make_pair(gx, gy)] = (int)v.size();
    v.push_back(make_pair(gx, gy));

    vector<vector<int>> d((int)v.size(), vector<int>(v.size(), 1e+9));
    for (int i = 0; i < (int)v.size(); i++) {
        int x = v[i].first, y = v[i].second;
        d[i][i] = 0;
        vector<vector<int>> dist(H, vector<int>(W, 1e+9));
        dist[x][y] = 0;
        queue<pair<int,int>> Q;
        Q.push(make_pair(x, y));

        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            int s = p.first;
            int t = p.second;

            for (int k = 0; k < 4; k++) {
                int x = s + dx[k], y = t + dy[k];
                if (!is_in(x, y) || dist[x][y] != 1e+9 || A[x][y] == '#') continue;
                dist[x][y] = dist[s][t] + 1;
                Q.push(make_pair(x, y));
                if (mp.count(make_pair(x, y))) {
                    d[i][mp[make_pair(x, y)]] = dist[x][y];
                }
            }
        }
    }

    vector<vector<int>> dp((1 << (int)v.size()), vector<int>(v.size(), 1e+9));
    dp[1][0] = 0;

    vector<pair<int,int>> w;
    for (int s = 1; s < (1 << (int)v.size()); s++) {
        if (!(s & 1)) continue;
        int c = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            if (s & (1 << i)) c++;
        }
        w.push_back(make_pair(c, s));
    }
    sort(w.begin(), w.end());

    for (auto p : w) {
        int s = p.second;
        for (int i = 0; i < (int)v.size(); i++) {
            if (!(s & (1 << i))) continue;
            if (i == 0 && s != 1) continue;
            for (int j = 0; j < (int)v.size(); j++) {
                if (s & (1 << j)) continue;
                dp[s + (1 << j)][j] = min(dp[s + (1 << j)][j], dp[s][i]+d[i][j]);
            }
        }
    }

    int ans = -1;
    for (int s = 1; s < (1 << v.size()); s++) {
        if (!(s & (1 << ((int)v.size()-1))) || dp[s][(int)v.size()-1] > T) continue;
        int c = 0;
        for (int i = 1; i < (int)v.size()-1; i++) {
            if (s & (1 << i)) c++;
        }
        ans = max(ans, c);
    }

    cout << ans << endl;
}
