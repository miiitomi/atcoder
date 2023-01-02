#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int P = (int)pow(2, N/2);
    vector<ll> X(P, 0);
    for (int p = 0; p < P; p++) {
        for (int i = 0; i < N/2; i++) {
            if (p & (1 << i)) {
                X[p] += A[i];
            }
        } 
    }

    int Q = (int)pow(2, N - N/2);
    vector<ll> Y(Q, 0);
    for (int q = 0; q < Q; q++) {
        for (int i = 0; i < N - N/2; i++) {
            if (q & (1 << i)) {
                Y[q] += A[N/2 + i];
            }
        }
    }
    sort(Y.begin(), Y.end());

    for (ll x : X) {
        ll y = *lower_bound(Y.begin(), Y.end(), K-x);
        if (x + y == K) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
