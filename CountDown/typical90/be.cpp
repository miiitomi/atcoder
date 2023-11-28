#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int s;
            cin >> s;
            A[i][s-1] = 1;
        }
    }
    vector<int> S(M);
    for (int i = 0; i < M; i++) cin >> S[i];

    int pos = 0;
    for (int j = 0; j < M && pos < N; j++) {
        for (int k = pos; k < N; k++) {
            if (A[k][j]) {
                swap(A[pos], A[k]);
                break;
            }
        }
        if (A[pos][j]) {
            for (int i = 0; i < N; i++) {
                if (i != pos && A[i][j]) {
                    for (int l = 0; l < M; l++) {
                        A[i][l] ^= A[pos][l];
                    }
                }
            }
            pos++;
        }
    }

    vector<int> v(M, 0);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j]) {
                if (v[j] != S[j]) {
                    for (int k = j; k < M; k++) v[k] ^= A[i][k];
                }
                break;
            }
            if (j == M-1) cnt++;
        }
    }

    if (v == S) {
        ll ans = 1;
        for (int k = 0; k < cnt; k++) ans = ans * 2 % MOD;
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }
}
