#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, Q, tmp = 0;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> E(N-1, 0);
    for (int i = 0; i < N-1; i++) {
        E[i] = A[i+1] - A[i];
        tmp += abs(E[i]);
    }
    while (Q--) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--;
        r--;
        if (l > 0) {
            tmp -= abs(E[l-1]);
            E[l-1] += v;
            tmp += abs(E[l-1]);
        }
        if (r < N-1) {
            tmp -= abs(E[r]);
            E[r] -= v;
            tmp += abs(E[r]);
        }
        cout << tmp << "\n";
    }
}
