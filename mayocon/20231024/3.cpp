// https://atcoder.jp/contests/abc258/tasks/abc258_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<ll> dp(N, (ll)1e+18);
    ll tmp_min = 1e+18;
    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += A[i] + B[i];
        X--;
        tmp_min = min(tmp_min, B[i]);
        dp[i] = tmp + ((ll)(X > 0)* X * tmp_min);
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
}
