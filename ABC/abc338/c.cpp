#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<ll> Q(N), A(N), B(N);
    for (int i = 0; i < N; i++) cin >> Q[i];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];


    ll ans = 0;
    for (int n = 0; n <= (int)1e+6; n++) {
        bool ok = true;
        vector<ll> R = Q;
        for (int i = 0; i < N; i++) R[i] -= n * A[i];
        ll tmp = 1e+9;
        for (int i = 0; i < N; i++) {
            if (R[i] < 0) ok = false;
            if (B[i] > 0) tmp = min(tmp, R[i] / B[i]);
        }
        if (ok) ans = max(ans, n + tmp);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
