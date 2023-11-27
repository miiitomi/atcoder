// https://atcoder.jp/contests/abc054/tasks/abc054_d
#include <bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
    if (a > b) a = b;
}

int main() {
    int N, M, ma, mb;
    cin >> N >> ma >> mb;
    M = N/2;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<int>> T(201, vector<int>(201, 1e+9));
    for (int s = 0; s < (1 << M); s++) {
        int cost = 0, sum_a = 0, sum_b = 0;
        for (int k = 0; k < M; k++) {
            if (s & (1 << k)) {
                cost += c[k];
                sum_a += a[k];
                sum_b += b[k];
            }
        }
        chmin(T[sum_a][sum_b], cost);
    }

    int ans = 1e+9;

    for (int s = 0; s < (1 << (N-M)); s++) {
        int cost = 0, sum_a = 0, sum_b = 0;
        for (int k = 0; k < (N-M); k++) {
            if (s & (1 << k)) {
                cost += c[M+k];
                sum_a += a[M+k];
                sum_b += b[M+k];
            }
        }
        for (int x = 0; x <= 200; x++) {
            int y = (sum_a+x)*mb;
            if (y % ma != 0) continue;
            y = y / ma - sum_b;
            if (0 <= y && y <= 200 && (sum_a != 0 || sum_b != 0 || x != 0 || y != 0)) {
                chmin(ans, cost + T[x][y]);
            }
        }
    }

    if (ans == 1e+9) cout << -1 << endl;
    else cout << ans << endl;
}
