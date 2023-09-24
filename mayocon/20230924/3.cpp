// https://atcoder.jp/contests/abc136/tasks/abc136_d
#include <bits/stdc++.h>
using namespace std;

string S;
int N;
vector<pair<int,int>> dp;

pair<int, int> rec(int u) {
    if (dp[u].first != -1) return dp[u];
    if (S[u] == 'R') {
        if (S[u+1] == 'L') {
            dp[u].first = u;
            dp[u].second = u+1;
        } else {
            auto q = rec(u+1);
            dp[u].first = q.second;
            dp[u].second = q.first;
        }
    } else {
        if (S[u-1] == 'R') {
            dp[u].first = u;
            dp[u].second = u-1;
        } else {
            auto q = rec(u-1);
            dp[u].first = q.second;
            dp[u].second = q.first;
        }
    }
    return dp[u];
}

int main() {
    cin >> S;
    N = (int)S.size();
    dp.assign(N, make_pair(-1, -1));

    for (int i = 0; i < N; i++) rec(i);

    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) ans[dp[i].first]++;

    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}
