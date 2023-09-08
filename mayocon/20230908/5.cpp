// https://atcoder.jp/contests/abc251/tasks/abc251_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<ll>> dp0(N+1, vector<ll>(2, 1e+17)), dp1(N+1, vector<ll>(2, 1e+17));
    dp0[0][0] = 0;
    dp1[0][1] = A[N-1];
    for (int i = 0; i < N; i++) {
        dp0[i+1][0] = min(dp0[i+1][0], dp0[i][1]);
        dp0[i+1][1] = min(dp0[i+1][1], min(dp0[i][0], dp0[i][1]) + A[i]);
        dp1[i+1][0] = min(dp1[i+1][0], dp1[i][1]);
        dp1[i+1][1] = min(dp1[i+1][1], min(dp1[i][0], dp1[i][1]) + A[i]);
    }

    ll ans1 = min(dp0[N][0], dp0[N][1]), ans2 = min(dp1[N-1][0], dp1[N-1][1]);
    cout << min(ans1, ans2) << endl;
}
