#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N, vector<int>(0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
        cout << i+1 << ": {";
        for (auto iter = G[i].begin(); iter != G[i].end();) {
            cout << 1 + (int)*iter;
            iter++;
            if (iter != G[i].end()) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
}
