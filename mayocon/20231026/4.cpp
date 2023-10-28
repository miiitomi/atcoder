// https://atcoder.jp/contests/abc079/tasks/abc079_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<pair<int,int>>> G(10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int c;
            cin >> c;
            if (i == j) continue;
            G[j].push_back(make_pair(i, c));
        }
    }

    vector<int> d(10, 1e+9);
    d[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push(make_pair(0, 1));
    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        if (d[p.second] != p.first) continue;
        for (auto q : G[p.second]) {
            if (d[q.first] > d[p.second] + q.second) {
                d[q.first] = d[p.second] + q.second;
                Q.push(make_pair(d[q.first], q.first));
            }
        }
    }

    int ans = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            int a;
            cin >> a;
            if (a == -1) continue;
            ans += d[a];
        }
    }

    cout << ans << endl;
}
