#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int max_value = -1;
    int max_idx = -1;
    for (int i = 0; i < N; i++) {
        if ((int)G[i].size() > max_value) {
            max_idx = i;
            max_value = G[i].size();
        }
    }

    cout << max_idx + 1 << endl;
}
