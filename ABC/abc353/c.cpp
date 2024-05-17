#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e+8;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) S[i+1] = S[i] + A[i];
    ll ans = 0;

    for (int i = 0; i < N-1; i++) {
        ans += (N-i-1)*A[i] + (S[N]-S[i+1]);
        auto iter = lower_bound(A.begin(), A.end(), MOD-A[i]);
        if (iter != A.end()) {
            int j = max(i+1, (int)distance(A.begin(), iter));
            ans -= (N-j)*MOD;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
