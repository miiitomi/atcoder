#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll _abs(ll x) {
    if (x >= 0LL) return x;
    else return -x;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N), E(N-1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0) E[i-1] = A[i] - A[i-1];
    }

    ll ans = 0;
    for (int i = 0; i < N-1; i++) ans += _abs(E[i]);

    for (int i = 0; i < Q; i++) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--;
        r--;
        if (l > 0) {
            ll E_new = E[l-1] + v;
            ans += -_abs(E[l-1]) + _abs(E_new);
            E[l-1] = E_new;
        }

        if (r < N-1) {
            ll E_new = E[r] - v;
            ans += -_abs(E[r]) + _abs(E_new);
            E[r] = E_new;
        }

        cout << ans << endl;
    }
}
