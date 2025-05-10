#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<vector<int>> V;
void rec(vector<int> &v, int r) {
    if (r == 0) {
        V.push_back(v);
        return;
    }
    int lim = r;
    if (!v.empty()) lim = min(lim, v.back());
    for (int k = 1; k <= lim; k++) {
        v.push_back(k);
        rec(v, r-k);
        v.pop_back();
    }
}

void solve() {
    ll N, T, M, K;
    cin >> N >> T >> M >> K;
    vector<int> v;
    rec(v, M);
    double p = 1.0 / N;
    vector<vector<double>> dp(T+1,vector<double>(K+1, 0));
    dp[T][K] = 1.0;
    for (int t = T-1; t >= 0; t--) {
        dp[t][K] = 1.0;
        for (int k = K-1; k >= 0; k--) {
            dp[t][k] = 0;
            for (auto w: V) {
                if ((int)w.size() > N) continue;
                double tmp = ((N - (int)w.size() + 0.0)/N) * dp[t+1][k];
                for (int x: w) {
                    tmp += p * (dp[t+1][min(k+x+0LL, K)]);
                }
                dp[t][k] = max(dp[t][k], tmp);
            }
        }
    }
    cout << dp.front().front() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
