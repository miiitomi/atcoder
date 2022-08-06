#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, L, R;
    cin >> N >> L >> R;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) {
        S[i+1] = S[i] + A[i];
    }

    vector<ll> Y(N+1, 0);
    ll now = 0;
    for (int i = N-1; i >= 0; i--) {
        Y[i] = now + A[i] - R;
        now = Y[i];
    }
    now = 0;
    for (int i = N-1; i >= 0; i--) {
        Y[i] = max(now, Y[i]);
        now = Y[i];
    }

    vector<ll> X(N+1, 0);
    for (ll i = 0; i <= N; i++) {
        X[i] = S[i] - (i*L) + Y[i];
    }

    ll a = *max_element(X.begin(), X.end());
    cout << S[N] - a << endl;
}
