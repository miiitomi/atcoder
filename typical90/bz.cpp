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
        if (a == b) continue;
        if (a < b) swap(a, b);
        G[a].push_back(b);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if ((int)G[i].size() == 1) ans++;
    }
    cout << ans << endl;
}
