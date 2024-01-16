#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> L(N, 0), R(N, 0);
    for (int i = 0; i < N; i++) {
        if (i == 0) L[i] = 1;
        else L[i] = min(L[i-1]+1, A[i]);
    }
    for (int i = N-1; i >= 0; i--) {
        if (i == N-1) R[i] = 1;
        else R[i] = min(R[i+1]+1, A[i]);
    }

    ll ans = -1;
    for (int i = 0; i < N; i++) ans = max(ans, min(L[i], R[i]));
    cout << ans << endl;
}
