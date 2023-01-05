#include <bits/stdc++.h>
using namespace std;

void rec(int i, vector<vector<int>> &G, vector<int> &d) {
    d[i] = 0;
    for (int j : G[i]) {
        if (d[j] == -1) {
            rec(j, G, d);
            d[i] = max(d[i], d[j] + 1);
        }
    }
}

int main() {
    int N, T;
    cin >> N >> T;
    T--;

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
    rec(T, G, d);

    for (int i = 0; i < N; i++) {
        cout << d[i];
        if (i == N-1) cout << endl;
        else cout << " ";
    }
}
