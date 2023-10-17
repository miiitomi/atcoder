// https://atcoder.jp/contests/abc136/tasks/abc136_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll S = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }

    vector<ll> X;
    X.reserve(2e+6);
    for (ll x = 1; x*x <= S; x++) {
        if (S % x == 0) {
            X.push_back(x);
            X.push_back(S/x);
        }
    }
    sort(X.begin(), X.end());
    reverse(X.begin(), X.end());

    for (ll x : X) {
        vector<ll> r(N);
        for (int i = 0; i < N; i++) r[i] = A[i] % x;
        sort(r.begin(), r.end());
        vector<ll> q(N+1, 0);
        for (int i = 0; i < N; i++) q[i+1] = q[i] + r[i];

        for (int k = 1; k <= N; k++) {
            if (q[k] <= K && q[k] == (N-k)*x - (q[N] - q[k])) {
                cout << x << endl;
                return 0;
            }
        }
    }
}
