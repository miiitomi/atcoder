#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, X, Y, M;
    cin >> N >> X >> Y;
    M = X+Y;
    vector<ll> A(M, 0), B(M, 0);
    for (int i = 0; i < N; i++) {
        ll p;
        char c;
        cin >> p >> c;
        if (c == 'A') A[i % M] += p;
        else B[i % M] += p;
    }
    vector<int> v(M);
    for (int i = 0; i < M; i++) v[i] = i;
    auto cmp = [&](const int &l, const int &r) {
        return A[l] - B[l] > A[r] - B[r];
    };
    sort(v.begin(), v.end(), cmp);
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        if (i < X) ans += A[v[i]];
        else ans += B[v[i]];
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
