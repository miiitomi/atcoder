#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int rec(vector<vector<int>> &G, vector<int> &d, int v) {
    int ans = 0;
    for (int w : G[v]) {
        ans += rec(G, d, w);
    }
    ans++;
    d[v] = ans;
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }
    vector<int> d(N, -1);
    rec(G, d, 0);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (G[i].size() <= 1) continue;
        int sum = 0;
        for (int v : G[i]) sum += d[v];
        vector<vector<bool>> dp(G[i].size(), vector<bool>(sum/2 + 1, false));
        dp[0][0] = true;
        if (d[G[i][0]] <= sum/2) dp[0][d[G[i][0]]] = true;
        for (int j = 1; j < (int)G[i].size(); j++) {
            for (int w = 0; w <= sum/2; w++) {
                if (!dp[j-1][w]) continue;
                dp[j][w] = true;
                if (w + d[G[i][j]] <= sum/2) dp[j][w + d[G[i][j]]] = true;
            }
        }
        for (int w = sum/2; w >= 0; w--) {
            if (dp[G[i].size()-1][w]) {
                ans += w * (sum - w);
                break;
            }
        }
    }
    cout << ans << endl;
}
