// https://atcoder.jp/contests/abc291/tasks/abc291_f
#include <bits/stdc++.h>
using namespace std;

void bfs(int N, int s, vector<vector<int>> &G, vector<int> &d) {
    d.assign(N, 1e+9);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] < 1e+9) continue;
            d[w] = d[v] + 1;
            Q.push(w);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N), H(N);
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        for (int j = 0; j < M; j++) {
            if (S[i][j] == '1') {
                G[i].push_back(i+j+1);
                H[i+j+1].push_back(i);
            }
        }
    }

    vector<int> d0, dN1;
    bfs(N, 0, G, d0);
    bfs(N, N-1, H, dN1);

    for (int i = 1; i < N-1; i++) {
        int tmp = 1e+9;
        for (int v = i-1; v >= max(0, i-10); v--) {
            for (int j = M-1; j >= 0; j--) {
                if (v+j+1<= i) break;
                if (S[v][j] == '0') continue;
                tmp = min(tmp, d0[v] + 1 + dN1[v+j+1]);
            }
        }
        if (tmp < 1e+9) cout << tmp << " ";
        else cout << -1 << " ";
    }
    cout << endl;
}
