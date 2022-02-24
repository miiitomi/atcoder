#include <bits/stdc++.h>
using namespace std;

vector<int> y = {1, -1, 0, 0};
vector<int> x = {0, 0, 1, -1};

int main() {
    int R, C;
    cin >> R >> C;
    pair<int, int> s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    s.first--;
    s.second--;
    g.first--;
    g.second--;
    vector<string> c(R);
    for (int i = 0; i < R; i++) cin >> c[i];

    vector<vector<int>> d(R, vector<int>(C, -1));
    d[s.first][s.second] = 0;
    queue<pair<int, int>> Q;
    Q.push(s);

    while (!Q.empty()) {
        pair<int, int> p = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> q;
            q.first = p.first + y[i];
            q.second = p.second + x[i];

            if (q.first < 0 || q.first >= R || q.second < 0 || q.second >= C) continue;
            if (c[q.first][q.second] == '#') continue;
            if (d[q.first][q.second] != -1) continue;

            if (q == g) {
                cout << d[p.first][p.second] + 1 << endl;
                return 0;
            }

            d[q.first][q.second] = d[p.first][p.second] + 1;
            Q.push(q);
        }
    }

    cout << -1 << endl;
}
