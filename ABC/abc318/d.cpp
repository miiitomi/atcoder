#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<vector<int>> D;
vector<ll> dp;

ll rec(int S) {
    if (dp[S] != -1) return dp[S];
    else if (S == 0) {
        dp[0] = 0;
        return dp[0];
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (!(S & (1 << i))) continue;
        for (int j = i+1; j < N; j++) {
            if (!(S & (1 << j))) continue;
            ans = max(ans, D[i][j] + rec(S - (1 << i) - (1 << j)));
        }
    }
    dp[S] = ans;
    return dp[S];
}

int main() {
    cin >> N;
    D.assign(N, vector<int>(N, -1));
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            cin >> D[i][j];
            D[j][i] = D[i][j];
        }
    }
    dp.assign((1 << N), -1);

    ll ans = rec((1 << N)-1);
    cout << ans << endl;
}
