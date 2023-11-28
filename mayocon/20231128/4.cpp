// https://atcoder.jp/contests/abc282/tasks/abc282_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> c(N, 0);
    ll ans = N*(N-1)/2 - M;

    for (int s = 0; s < N; s++) {
        if (c[s] != 0) continue;
        ll cnt_p = 0, cnt_n = 0;
        queue<int> Q;
        Q.push(s);
        c[s] = 1;
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            if (c[v] > 0) cnt_p++;
            else cnt_n++;
            for (int w : G[v]) {
                if (c[w] != 0) {
                    if (c[w] == c[v]) {
                        cout << 0 << endl;
                        return 0;
                    }
                } else {
                    c[w] = -c[v];
                    Q.push(w);
                }
            }
        }
        ans -= cnt_p*(cnt_p-1)/2;
        ans -= cnt_n*(cnt_n-1)/2;
    }
    cout << ans << endl;
}
