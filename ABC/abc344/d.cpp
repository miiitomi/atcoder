#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

void solve() {
    string T;
    int N;
    cin >> T >> N;
    int M = T.size();
    vector<int> A(N);
    vector<vector<string>> S(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i].resize(A[i]);
        for (int j = 0; j < A[i]; j++) cin >> S[i][j];
    }

    vector<vector<int>> dp(N+1, vector<int>(M+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        for (int j = 0; j < M; j++) {
            if (dp[i][j] == INF) continue;
            for (string &s : S[i]) {
                if (j + (int)s.size() > M) continue;
                bool is_ok = true;
                for (int k = 0; k < (int)s.size(); k++) {
                    if (s[k] != T[j+k]) {
                        is_ok = false;
                        break;
                    }
                }
                if (is_ok) dp[i+1][j+s.size()] = min(dp[i+1][j+s.size()], dp[i][j]+1);
            }
        }
    }

    if (dp.back().back() == INF) cout << -1 << endl;
    else cout << dp.back().back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
