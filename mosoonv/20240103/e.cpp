// https://atcoder.jp/contests/abc310/tasks/abc310_d
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int N, T, M;
vector<vector<int>> G;

void dfs(int i, vector<int> v) {
    if (i == N) {
        if (v.size() == T) ans++;
        return;
    }

    for (int j = 0; j < v.size(); j++) {
        bool ok = true;
        for (int k : G[i]) {
            if (v[j] & (1 << k)) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        vector<int> w = v;
        w[j] += (1 << i);
        dfs(i+1, w);
    }

    if ((int)v.size() < T) {
        v.push_back(1 << i);
        dfs(i+1, v);
    }
    return;
}

int main() {
    cin >> N >> T >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, vector<int>{});

    cout << ans << endl;
}
