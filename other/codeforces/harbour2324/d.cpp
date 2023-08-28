#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> B(N, vector<int>(N, 0)), C(N, vector<int>(N, 0));

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < N-1) {
                if (j > 0) B[i+1][j-1] ^= B[i][j];
                else B[i+1][0] ^= B[i][0];
                if (j < N-1) C[i+1][j+1] ^= C[i][j];
            }
            if (j > 0) {
                B[i][j] ^= B[i][j-1];
                C[i][j] ^= C[i][j-1];
            }
            if (((int)(A[i][j]-'0'))^(B[i][j]^C[i][j])) {
                ans++;
                if (i < N-1) {
                    if (j > 0) B[i+1][j-1] ^= 1;
                    else B[i+1][0] ^= 1;
                    if (j < N-2) C[i+1][j+2] ^= 1;
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
