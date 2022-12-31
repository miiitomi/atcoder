// A06

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> S(N+1, 0);
    for (int i = 0; i < N; i++) {
        S[i+1] = S[i] + A[i];
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << S[r+1] - S[l] << endl;
    }
}
