// https://atcoder.jp/contests/abc136/tasks/abc136_d
#include <bits/stdc++.h>
using namespace std;

string S;
vector<pair<int,int>> dp;

pair<int,int> rec(int i) {
    if (dp[i].first != -1) return dp[i];
    pair<int,int> p;
    if (S[i] == 'R') p = rec(i+1);
    else p = rec(i-1);
    dp[i] = {p.second, p.first};
    return dp[i];
}

void solve() {
    cin >> S;
    int N = S.size();
    dp.assign(N, {-1, -1});
    for (int i = 0; i < N-1; i++) {
        if (S[i] == 'R' && S[i+1] == 'L') {
            dp[i] = {i, i+1};
            dp[i+1] = {i+1, i};
        }
    }
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        auto p = rec(i);
        ans[p.first]++;
    }
    for (int a : ans) cout << a << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
