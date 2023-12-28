// https://atcoder.jp/contests/abc287/tasks/abc287_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll N;
vector<vector<int>> G;

vector<vector<ll>> rec(int v, int par) {
    vector<vector<ll>> dp(2, vector<ll>(2, 0));
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int c : G[v]) {
        if (c == par) continue;
        vector<vector<ll>> ret = rec(c, v);
        vector<vector<ll>> ndp(dp.size()+ret.size()-1, vector<ll>(2, 0));
        for (int i = 0; i < (int)dp.size(); i++) {
            for (int j = 0; j < (int)ret.size() && i+j < (int)ndp.size(); j++) {
                ndp[i+j][0] = (ndp[i+j][0] + dp[i][0] * ret[j][0]) % MOD;
                ndp[i+j][0] = (ndp[i+j][0] + dp[i][0] * ret[j][1]) % MOD;
                ndp[i+j][1] = (ndp[i+j][1] + dp[i][1] * ret[j][0]) % MOD;
                if (i+j-1 >= 0) ndp[i+j-1][1] = (ndp[i+j-1][1] + dp[i][1] * ret[j][1]) % MOD;
            }
        }
        swap(dp, ndp);
    }
    return dp;
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<ll>> dp = rec(0, -1);
    for (int i = 1; i <= N; i++) {
        cout << (dp[i][0] + dp[i][1]) % MOD << endl;
    }
}
