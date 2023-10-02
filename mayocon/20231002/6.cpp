// https://atcoder.jp/contests/abc195/tasks/abc195_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S, X;
    cin >> N >> S >> X;

    vector<set<int>> dp(N+1);
    dp[N].insert(0);

    for (int i = N-1; i >= 0; i--) {
        for (int r = 0; r <= 6; r++) {
            if (X[i] == 'T') {if (dp[i+1].count(10*r % 7) || dp[i+1].count((10*r+((int)(S[i] - '0')))%7)) dp[i].insert(r);}
            else {if (dp[i+1].count(10*r % 7) && dp[i+1].count((10*r+((int)(S[i] - '0')))%7)) dp[i].insert(r);}
        }
    }

    if (dp[0].count(0)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}
