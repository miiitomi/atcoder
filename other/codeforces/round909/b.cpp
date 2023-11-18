#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }

    ll ans = 0;
    for (int k = 1; k <= N; k++) {
        if (N % k != 0) continue;
        ll min_v = 1e+18;
        ll max_v = -1e+18;
        for (int l = 0; l < N; l += k) {
            ll tmp = S[l + k] - S[l];
            min_v = min(min_v, tmp);
            max_v = max(max_v, tmp);
        }
        ans = max(ans, max_v-min_v);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
