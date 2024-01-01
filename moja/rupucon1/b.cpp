#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll N, X;
vector<ll> A;
vector<ll> dp;

int main() {
    cin >> N >> X;
    A.assign(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];

    dp.assign(max(N,X)+1, 0);
    deque<ll> Q;
    ll tmp = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = A[i];
        Q.push_back(A[i]);
        tmp = (tmp + A[i]) % MOD; 
    }

    for (int j = N+1; j <= X; j++) {
        dp[j] = tmp;
        ll x = Q.front();
        Q.pop_front();
        tmp = (tmp - x + MOD) % MOD;
        x = dp[j];
        tmp = (tmp + x) % MOD;
        Q.push_back(x);
    }

    cout << dp[X] << endl;
}
