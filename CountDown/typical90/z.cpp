#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;

void dfs(int v, vector<int> &c) {
    for (int w : G[v]) {
        if (c[w] != 0) continue;
        c[w] = -c[v];
        dfs(w, c);
    }
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> c(N, 0);
    c[0] = 1;
    dfs(0, c);

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (c[i] == 1) cnt++;
    }

    if (cnt >= N/2) {
        int x = N/2;
        for (int i = 0; x > 0; i++) {
            if (c[i] == 1) {
                cout << i+1 << " ";
                x--;
            }
        }
    } else {
        int x = N/2;
        for (int i = 0; x > 0; i++) {
            if (c[i] == -1) {
                cout << i+1 << " ";
                x--;
            }
        }        
    }
    cout << endl;
}
