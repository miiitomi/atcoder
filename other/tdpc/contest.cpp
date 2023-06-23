#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    int N;
    cin >> N;
    vector<vector<bool>> dp(N+1, vector<bool>(10001, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        for (int x = 0; x <= 10000; x++) {
            if (dp[i][x]) {
                dp[i+1][x] = true;
                if (x + p <= 10000) dp[i+1][x+p] = true;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= 10000; j++) {
        if (dp[N][j]) ans++;
    }

    cout << ans << endl;
}
