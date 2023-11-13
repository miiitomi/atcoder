// https://atcoder.jp/contests/typical90/tasks/typical90_am
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<vector<int>> G;
vector<ll> siz, weight;
ll ans = 0;

void rec(int v, int p) {
    for (int w : G[v]) {
        if (w != p) {
            rec(w, v);
            siz[v] += siz[w];
        }
    }
    siz[v]++;
    for (int w : G[v]) {
        if (w != p) {
            ans += (siz[v] - siz[w]) * (weight[w] + siz[w]);
            weight[v] += weight[w] + siz[w];
        }
    }
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    siz.assign(N, 0);
    weight.assign(N, 0);
    rec(0, -1);
    cout << ans << endl;
}
