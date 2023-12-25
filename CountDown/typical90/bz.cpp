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

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j : G[i]) {
            if (j < i) tmp++;
        }
        if (tmp == 1) ans++;
    }
    cout << ans << endl;
}
