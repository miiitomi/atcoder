// https://atcoder.jp/contests/abc288/tasks/abc288_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<ll>> S(N+1, vector<ll>(K, 0));
    for (int i = 0; i < N; i++) {
        S[i+1] = S[i];
        S[i+1][i % K] += A[i];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        ll x = S[r][0] - S[l][0];
        bool ok = true;
        for (int j = 1; j < K; j++) if (x != S[r][j]-S[l][j]) ok = false;
        if (ok) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}
