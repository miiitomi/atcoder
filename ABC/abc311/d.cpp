#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &G, vector<bool> &reached, int v) {
    for (int nv : G[v]) {
        if (reached[nv]) continue;
        reached[nv] = true;
        dfs(G, reached, nv);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    int K = N*M*5;
    vector<vector<int>> G(K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == '#') continue;
            int c = (M * i) + j;
            for (int k = 1; k <= 4; k++) {
                G[5*c].push_back(5*c+k);
            }
            if (S[i-1][j] != '#') G[5*c+1].push_back(5*(c-M)+1);
            else G[5*c+1].push_back(5*c);
            if (S[i+1][j] != '#') G[5*c+2].push_back(5*(c+M)+2);
            else G[5*c+2].push_back(5*c);
            if (S[i][j-1] != '#') G[5*c+3].push_back(5*(c-1)+3);
            else G[5*c+3].push_back(5*c);
            if (S[i][j+1] != '#') G[5*c+4].push_back(5*(c+1)+4);
            else G[5*c+4].push_back(5*c);
        }
    }
    vector<bool> reached(K, false);
    int c = 1*M + 1;
    reached[5*c] = true;

    dfs(G, reached, 5*c);


    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int s = (M * i) + j;
            bool r = false;
            for (int k = 0; k <= 4; k++) {
                if (reached[5*s+k]) r = true;
            }
            if (r) ans++;
        }
    }

    cout << ans << endl;
}
