// https://atcoder.jp/contests/abc227/tasks/abc227_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    ll M, N;
    cin >> S >> M;
    N = S.size();
    M = min(M, N*N);

    int K = 0, E = 0, Y = 0;
    for (char c : S) {
        if (c == 'K') K++;
        else if (c == 'E') E++;
        else Y++;
    }

    vector<vector<vector<vector<pair<ll,string>>>>> dp(N+1, vector<vector<vector<pair<ll,string>>>>(M+1, vector<vector<pair<ll,string>>>(K+1, vector<pair<ll, string>>(E+1, make_pair(0LL, "")))));
    dp[0][0][0][0] = make_pair(1LL, S);

    for (int i = 0; i < N; i++) {
        for (int m = 0; m <= M; m++) {
            for (int k = 0; k <= K; k++) {
                for (int e = 0; e <= E; e++) {
                    if (dp[i][m][k][e].first == 0) continue;
                    int y = i - k - e;
                    string U = dp[i][m][k][e].second;
                    if (k < K) {
                        string T = U;
                        int j = 0, cnt=0;
                        while (T[j] != 'K') j++;
                        while (j != 0) {
                            swap(T[j-1], T[j]);
                            j--;
                            cnt++;
                        }
                        reverse(T.begin(), T.end());
                        T.pop_back();
                        reverse(T.begin(), T.end());
                        if (m + cnt <= M) {
                            dp[i+1][m+cnt][k+1][e].first += dp[i][m][k][e].first;
                            dp[i+1][m+cnt][k+1][e].second = T;
                        }
                    }
                    if (e < E) {
                        string T = U;
                        int j = 0, cnt=0;
                        while (T[j] != 'E') j++;
                        while (j != 0) {
                            swap(T[j-1], T[j]);
                            j--;
                            cnt++;
                        }
                        reverse(T.begin(), T.end());
                        T.pop_back();
                        reverse(T.begin(), T.end());
                        if (m + cnt <= M) {
                            dp[i+1][m+cnt][k][e+1].first += dp[i][m][k][e].first;
                            dp[i+1][m+cnt][k][e+1].second = T;
                        }
                    }
                    if (y < Y) {
                        string T = U;
                        int j = 0, cnt=0;
                        while (T[j] != 'Y') j++;
                        while (j != 0) {
                            swap(T[j-1], T[j]);
                            j--;
                            cnt++;
                        }
                        reverse(T.begin(), T.end());
                        T.pop_back();
                        reverse(T.begin(), T.end());
                        if (m + cnt <= M) {
                            dp[i+1][m+cnt][k][e].first += dp[i][m][k][e].first;
                            dp[i+1][m+cnt][k][e].second = T;
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int m = 0; m <= M; m++) ans += dp[N][m][K][E].first;
    cout << ans << endl;
}
