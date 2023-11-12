// https://atcoder.jp/contests/abc164/tasks/abc164_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = (int)(S[i] - '0');

    vector<int> dp(2019, 0), dp_new(2019, 0);
    dp[v[0]]++;
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        int x = v[i];
        dp_new.assign(2019, 0);
        for (int y = 0; y < 2019; y++) dp_new[(10*y + x) % 2019] = dp[y];
        dp = dp_new;
        ans += dp[0];
        dp[x]++;
    }
    cout << ans << endl;
}
