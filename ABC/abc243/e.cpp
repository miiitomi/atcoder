#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e+18;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) dist[i][i] = 0;
    vector<ll> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
        dist[A[i]][B[i]] = C[i];
        dist[B[i]][A[i]] = C[i];
    }

    for (int k = 0; k < N; k++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (dist[A[i]][B[i]] < C[i]) {
            ans++;
        } else {
            for (int k = 0; k < N; k++) {
                if (k == A[i] || k == B[i]) continue;
                if (dist[A[i]][k] + dist[k][B[i]] == C[i]) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}
