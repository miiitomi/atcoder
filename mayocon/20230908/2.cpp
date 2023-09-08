// https://atcoder.jp/contests/abc313/tasks/abc313_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> can_saikyo(N, true);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        can_saikyo[b] = false;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += can_saikyo[i];

    if (cnt > 1) cout << -1 << endl;
    else for (int i = 0; i < N; i++) if (can_saikyo[i]) cout << i+1 << endl;
}
