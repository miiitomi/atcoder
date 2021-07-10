#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int clr, vector<int> &color, vector<vector<int>> &G) {
    if (color[x] != 0) {
        return;
    }
    color[x] = clr;
    for (int y : G[x]) {
        dfs(y, -clr, color, G);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    vector<int> c(Q), d(Q);
    for (int i = 0; i < Q; i++) cin >> c[i] >> d[i];

    vector<int> color(N, 0);
    dfs(0, 1, color, G);

    for (int i = 0; i < Q; i++) {
        if (color[c[i]-1] == color[d[i]-1]) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
}
