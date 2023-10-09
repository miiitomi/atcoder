// https://atcoder.jp/contests/abc195/tasks/abc195_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S, X;
    cin >> N >> S >> X;

    vector<int> dp(N+1, 0);
    dp[N] = 1;

    for (int i = N-1; i >= 0; i--) {
        for (int k = 0; k < 7; k++) {
            bool zero = dp[i+1] & (1 << (10*k%7));
            bool add = dp[i+1] & (1 << ((10*k + (int)(S[i]-'0'))%7));
            if (X[i] == 'A'){
                if (zero && add) dp[i] += (1 << k);
            } else {
                if (zero || add) dp[i] += (1 << k);
            }
        }
    }

    if (dp[0] & 1) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}
