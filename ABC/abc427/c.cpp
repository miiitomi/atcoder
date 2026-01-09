#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    int ans = 1e+9;
    for (int s = 0; s < (1 << N); s++) {
        int tmp = 0;
        for (int i = 0; i < M; i++) {
            if (((s & (1 << u[i])) > 0) == ((s & (1 << v[i])) > 0)) tmp++;
        }
        if (ans > tmp) {
            ans = tmp;
        }
    }
    cout << ans << "\n";
}
