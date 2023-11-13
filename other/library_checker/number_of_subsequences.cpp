#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> dp(N+1, 0), S(N+2, 0);
    dp[0] = 1;

    map<int,int> mp;
    for (int i = 1; i <= N; i++) {
        S[i] = (S[i-1] + dp[i-1]) % MOD;
        int a = A[i-1];
        int k = 0;
        if (mp.count(a)) k = mp[a];
        dp[i] = (S[i] - S[k] + MOD) % MOD;
        mp[a] = i;
    }
    S[N+1] = (S[N] + dp[N]) % MOD;
    cout << S[N+1] - S[1] << endl;
}
