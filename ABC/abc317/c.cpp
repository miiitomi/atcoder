#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N, -1));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = c;
        G[b][a] = c;
    }

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;

    int ans = -1;
    do {
        int tmp = 0;
        int x = v[0];
        for (int i = 1; i < N; i++) {
            int y = v[i];
            if (G[x][y] == -1) break;
            tmp += G[x][y];
            x = y;
        }
        ans = max(ans, tmp);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
