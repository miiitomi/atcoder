#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

void chmin(int &a, int b) {
    if (a > b) a = b;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }
    int M;
    cin >> M;
    vector<set<int>> V(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        V[x].insert(y);
        V[y].insert(x);
    }

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(1 << N, vector<int>(N, INF)));
    for (int i = 0; i < N; i++) {
        dp[0][1 << i][i] = A[i][0];
    }
    for (int i = 0; i < N-1; i++) {
        for (int s = 0; s < (1 << N); s++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (s & (1 << j)) count++;
            }
            if (count - 1 != i) continue;

            for (int j = 0; j < N; j++) {
                if (!(s & (1 << j))) continue;
                for (int k = 0; k < N; k++) {
                    if (j == k || s & (1 << k) || V[j].count(k)) continue;
                    chmin(dp[i+1][s | (1 << k)][k], dp[i][s][j] + A[k][i+1]);
                }
            }
        }
    }

    int ans = *min_element(dp[N-1][(1 << N) - 1].begin(), dp[N-1][(1 << N) - 1].end());
    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
}
