// https://atcoder.jp/contests/abc054/tasks/abc054_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a][b] = 1;
        A[b][a] = 1;
    }

    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) v[i] = i;
    int ans = 0;
    do {
        if (v[0] != 0)  break;
        bool ok = true;
        for (int i = 0; i+1 < (int)v.size(); i++) {
            int s = v[i], t = v[i+1];
            if (A[s][t] == 0) ok = false;
        }
        if (ok) {
            ans++;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
