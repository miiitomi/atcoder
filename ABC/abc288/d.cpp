#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<ll>> S(K, vector<ll>(N+1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (i % K == j) {
                S[j][i+1] = S[j][i] + A[i];
            } else {
                S[j][i+1] = S[j][i];
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        ll x = S[0][r+1] - S[0][l];
        bool yes = true;
        for (int j = 1; j < K; j++) {
            if (x != S[j][r+1] - S[j][l]) {
                yes = false;
                break;
            }
        }
        if (yes) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

}
