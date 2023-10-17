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
        ll s = 0;
        for (int i = 0; i < N; i++) {
            r[i] = A[i] % x;
            s += r[i];
        }
        sort(r.begin(), r.end());
        s /= x;
        ll y = 0;
        for (int k = 0; k < N - s; k++) y += r[k];
        if (y <= K) {
            cout << x << endl;
            return 0;
        }
    }
}
