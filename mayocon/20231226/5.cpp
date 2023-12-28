// https://atcoder.jp/contests/abc054/tasks/abc054_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    while (M--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a][b] = true;
        G[b][a] = true;
    }

    vector<int> v(N-1);
    for (int i = 0; i < N-1; i++) v[i] = i+1;
    int ans = 0;
    do {
        bool ok = true;
        int tmp = 0;
        for (int u : v) {
            if (!G[tmp][u]) {
                ok = false;
                break;
            }
            tmp = u;
        }
        if (ok) ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
