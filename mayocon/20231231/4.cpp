// https://atcoder.jp/contests/abc318/tasks/abc318_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<vector<int>> D;
ll ans = -1;

void dfs(int s, vector<pair<int,int>> V, int r) {
    if (V.size() == N/2) {
        ll tmp = 0;
        for (auto p : V) tmp += D[p.first][p.second];
        ans = max(ans, tmp);
        return;
    }
    int u = 0;
    while ((s & (1 << u)) || u == r) u++;
    s += (1 << u);
    for (int v = 0; v < N; v++) {
        if (v != r && !(s & (1 << v))) {
            V.push_back(make_pair(u, v));
            dfs(s + (1 << v), V, r);
            V.pop_back();
        }
    }
}

int main() {
    cin >> N;
    D.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            cin >> D[i][j];
            D[j][i] = D[i][j];
        }
    }

    if (N & 1) {
        for (int u = 0; u < N; u++) dfs(0, vector<pair<int,int>>{}, u);
    } else {
        dfs(0, vector<pair<int,int>>{}, -1);
    }

    cout << ans << endl;
}
