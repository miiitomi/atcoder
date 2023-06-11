#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> visited(N, false);
    visited[0] = true;
    vector<int> path;
    path.push_back(0);

    while (true) {
        int K;
        cin >> K;
        vector<int> v(K);
        for (int i = 0; i < K; i++) {
            cin >> v[i];
            if (v[i] == N) {
                cout << N << endl;
                string S;
                cin >> S;
                return 0;
            }
            v[i]--;
        }

        bool exists_unvisited = false;
        for (int u : v) {
            if (!visited[u]) {
                exists_unvisited = true;
                visited[u] = true;
                path.push_back(u);
                cout << u + 1 << endl;
                break;
            }
        }

        if (!exists_unvisited) {
            path.pop_back();
            int u = path.back();
            cout << u + 1 << endl;
        }
    }
}
