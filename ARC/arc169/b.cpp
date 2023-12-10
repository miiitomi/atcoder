#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> p(N);
    queue<int> Q;
    ll tmp = 0;
    int j = 0;

    for (int i = 0; i < N; i++) {
        while (j < N && tmp + A[j] <= S) {
            tmp += A[j];
            Q.push(A[j]);
            j++;
        }
        p[i] = j;
        ll x = Q.front();
        Q.pop();
        tmp -= x;
    }

    ll ans = 0;
    vector<ll> dp(N);
    for (int i = N-1; i >= 0; i--) {
        if (p[i] == N) dp[i] = N-i;
        else dp[i] = N - i + dp[p[i]];
        ans += dp[i];
    }
    cout << ans << endl;
}
