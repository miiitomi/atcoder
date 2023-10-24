// https://atcoder.jp/contests/abc136/tasks/abc136_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K, S;
vector<ll> A;

bool is_ok(ll x) {
    vector<ll> r(N);
    ll T = 0;
    for (int i = 0; i < N; i++) {
        r[i] = A[i] % x;
        T += x - r[i];
    }
    sort(r.begin(), r.end());
    ll Q = 0;

    for (int i = 0; i < N; i++) {
        Q += r[i];
        T -= (x - r[i]);
        if (Q <= K && Q == T) return true;
    }
    return false;
}

int main() {
    cin >> N >> K;
    S = 0;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S += A[i];
    }

    vector<ll> X;
    X.reserve(1e+6);
    for (ll x = 1; x*x <= S; x++) {
        if (S % x == 0) {
            X.push_back(x);
            X.push_back(S/x);
        }
    }
    sort(X.begin(), X.end());
    reverse(X.begin(), X.end());

    for (ll x : X) {
        if (S % x != 0) continue;
        if (is_ok(x)) {
            cout << x << endl;
            return 0;
        }
    }
}
