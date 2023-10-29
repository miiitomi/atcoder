#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N+1, 0), B(N+1, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[a]++;
    }

    for (ll x = N; x >= 1; x--) {
        ll cnt = 0;
        for (ll y = x; y <= N; y += x) cnt += A[y];
        B[x] = (cnt * (cnt-1)) / 2LL;
        for (ll y = 2*x; y <= N; y += x) B[x] -= B[y];
    }

    ll ans = N * (N-1) / 2LL;

    for (ll x = 1; x <= N; x++) {
        if (A[x] == 0) continue;
        for (ll y = x; y <= N; y += x) {
            ans -= B[y];
            B[y] = 0;
        }
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
