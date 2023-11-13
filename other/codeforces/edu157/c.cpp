#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<vector<vector<vector<ll>>>> dp(6, vector<vector<vector<ll>>>(6, vector<vector<ll>>(46, vector<ll>(46, 0))));
    for (string s : S) {
        for (int l = 1; l <= s.size(); l++) {
            int r = s.size() - l;
            int a=0, b=0;
            for (int i = 0; i < s.size(); i++) {
                if (i < l) a += (int)(s[i] - '0');
                else b += (int)(s[i] - '0');
            }
            dp[l][r][a][b]++;
        }
    }

    ll ans = 0;
    for (string s : S) {
        int m = s.size();
        for (int k = 1; k <= 5; k++) {
            if ((k + m) % 2 != 0) continue;
            int y = (k + m) / 2;
            if (y <= k) {
                int c = 0;
                for (char q : s) c += (int)(q - '0');
                for (int p = 0; p <= 45; p++) {
                    int t = p - c;
                    if (0 <= t && t < 46) ans += dp[y][k-y][p][t];
                }
            } else {
                int c=0, d=0, cnt=0;
                for (int j = s.size()-1; j >= 0; j--) {
                    if (cnt < y) {
                        d += (int)(s[j] - '0');
                        cnt++;
                    } else {
                        c += (int)(s[j] - '0');
                    }
                }
                int l = d - c;
                if (0 <= l && l < 46) ans += dp[k][0][l][0];
            }
        }
    }

    cout << ans << endl;
}
