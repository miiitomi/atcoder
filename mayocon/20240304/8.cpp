// https://atcoder.jp/contests/abc259/tasks/abc259_h
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int N;
vector<mint> F(1000, 1);
mint comb(int n, int r) {return F[n]/(F[n-r]*F[r]);}
vector<vector<mint>> C(1000, vector<mint>(1000, 1));

mint solve_combination(vector<pair<int,int>> &v) {
    mint tmp = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v.size(); j++) {
            if (v[i].first > v[j].first || v[i].second > v[j].second) continue;
            int n = v[j].first - v[i].first + v[j].second - v[i].second;
            int r = v[j].first - v[i].first;
            tmp += C[n][r];
        }
    }
    return tmp;
}

mint solve_dp(vector<pair<int,int>> &v) {
    vector<vector<mint>> dp(N, vector<mint>(N, 0));
    for (auto p : v) dp[p.first][p.second] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < N-1) dp[i+1][j] += dp[i][j];
            if (j < N-1) dp[i][j+1] += dp[i][j];
        }
    }
    mint tmp = 0;
    for (auto p : v) tmp += dp[p.first][p.second];
    return tmp;
}

void solve() {
    cin >> N;
    vector<vector<pair<int,int>>> V(N*N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            a--;
            V[a].push_back(make_pair(i, j));
        }
    }
    mint ans = 0;
    for (int i = 0; i < N*N; i++) {
        if ((int)V[i].size() > N) ans += solve_dp(V[i]);
        else ans += solve_combination(V[i]);
    }
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < 1000; x++) F[x] = F[x-1] * x;
    for (int n = 0; n < 1000; n++) {
        for (int r = 0; r <= n; r++) {
            C[n][r] = comb(n, r);
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
