// https://atcoder.jp/contests/abc302/tasks/abc302_f
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(M+N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        while (a--) {
            int s;
            cin >> s;
            s--;
            G[s].push_back(M+i);
            G[M+i].push_back(s);
        }
    }

    vector<int> d(M+N, 1e+9);
    d[0] = 0;
    queue<int> Q;
    Q.push(0);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (d[w] > d[v] + 1) {
                d[w] = d[v] + 1;
                Q.push(w);
            }
        }
    }

    if (d[M-1] > 1e+8) cout << -1 << endl;
    else cout << (d[M-1]-2)/2 << endl;
}
