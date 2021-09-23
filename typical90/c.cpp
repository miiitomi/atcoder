#include <bits/stdc++.h>
using namespace std;

void rec(vector<vector<int>> &G, vector<int> &d, int v) {
    for (int w : G[v]) {
        if (d[w] != -1) continue;
        d[w] = d[v] + 1;
        rec(G, d, w);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> d(N, -1);
    d[0] = 0;
    rec(G, d, 0);
    int v = distance(d.begin(), max_element(d.begin(), d.end()));
    d.assign(N, -1);
    d[v] = 0;
    rec(G, d, v);
    cout << *max_element(d.begin(), d.end()) + 1 << endl;
}
