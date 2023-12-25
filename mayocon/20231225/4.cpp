// https://atcoder.jp/contests/abc315/tasks/abc315_e
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> C;
vector<vector<int>> P;
vector<bool> reached;
vector<int> ans;

void dfs(int u) {
    reached[u] = true;
    for (int v : P[u]) {
        if (!reached[v]) {
            dfs(v);
        }
    }
    ans.push_back(u+1);
}

int main() {
    cin >> N;
    C.resize(N);
    P.resize(N);
    reached.assign(N, false);

    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int x;
            cin >> x;
            P[i].push_back(x-1);
        }
    }

    dfs(0);
    for (int u : ans) if (u != 1) cout << u << " ";
    cout << endl;
}
