// https://atcoder.jp/contests/abc241/tasks/abc241_f
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    pair<int,int> s, g;
    cin >> s.first >> s.second >> g.first >> g.second;
    map<int,vector<int>> X, Y;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    for (auto iter = X.begin(); iter != X.end(); iter++) sort(iter->second.begin(), iter->second.end());
    for (auto iter = Y.begin(); iter != Y.end(); iter++) sort(iter->second.begin(), iter->second.end());

    queue<pair<int,int>> Q;
    map<pair<int,int>, int> d;
    Q.push(s);
    d[s] = 0;

    while (!Q.empty()) {
        pair<int,int> p = Q.front();
        Q.pop();

        int x = p.first, y = p.second;

        if (X.count(x)) {
            auto iter = lower_bound(X[x].begin(), X[x].end(), y);
            if (iter != X[x].end()) {
                int y_ = *iter - 1;
                if (!d.count(make_pair(x, y_))) {
                    d[make_pair(x, y_)] = d[p] + 1;
                    Q.push(make_pair(x, y_));
                }
            }
            if (iter != X[x].begin()) {
                iter--;
                int y_ = *iter + 1;
                if (!d.count(make_pair(x, y_))) {
                    d[make_pair(x, y_)] = d[p] + 1;
                    Q.push(make_pair(x, y_));
                }
            }
        }

        if (Y.count(y)) {
            auto iter = lower_bound(Y[y].begin(), Y[y].end(), x);
            if (iter != Y[y].end()) {
                int x_ = *iter - 1;
                if (!d.count(make_pair(x_, y))) {
                    d[make_pair(x_, y)] = d[p] + 1;
                    Q.push(make_pair(x_, y));
                }
            }
            if (iter != Y[y].begin()) {
                iter--;
                int x_ = *iter + 1;
                if (!d.count(make_pair(x_, y))) {
                    d[make_pair(x_, y)] = d[p] + 1;
                    Q.push(make_pair(x_, y));
                }
            }
        }
    }

    if (!d.count(g)) cout << -1 << "\n";
    else cout << d[g] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
